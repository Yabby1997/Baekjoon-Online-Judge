import Foundation

struct Queue<T> {
    var queue: [T] = []
    
    mutating func push(_ element: T) {
        self.queue.append(element)
    }
    
    mutating func pop() {
        if queue.isEmpty {
            print(-1)
        } else {
            print(queue.first!)
            self.queue.remove(at: 0)
        }
    }
    
    func size() {
        print(self.queue.count)
    }
    
    func isEmpty() {
        if self.queue.isEmpty {
            print(1)
        } else {
            print(0)
        }
    }
    
    func back() {
        if self.queue.isEmpty {
            print(-1)
        } else {
            print(self.queue.last!)
        }
    }
    
    func front() {
        if self.queue.isEmpty {
            print(-1)
        } else {
            print(self.queue.first!)
        }
    }
}

var queue:Queue<Int> = Queue<Int>()
let numOfInstructions = Int(readLine()!)!

for _ in 1...numOfInstructions {
    let instruction = readLine()!.split(separator: " ")
    switch instruction[0] {
    case "push" : queue.push(Int(instruction[1])!)
    case "pop" : queue.pop()
    case "size" : queue.size()
    case "empty" : queue.isEmpty()
    case "front" : queue.front()
    case "back" : queue.back()
    default:
        print("ERR")
    }
}

