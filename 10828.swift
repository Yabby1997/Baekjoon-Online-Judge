import Foundation

struct Stack<T> {
    var stack: [T] = []
    
    mutating func push(_ element: T) {
        self.stack.append(element)
    }
    
    mutating func pop() {
        if stack.isEmpty {
            print(-1)
        } else {
            print(stack.last!)
            self.stack.remove(at: self.stack.count - 1)
        }
    }
    
    func size() {
        print(self.stack.count)
    }
    
    func isEmpty() {
        if self.stack.isEmpty {
            print(1)
        } else {
            print(0)
        }
    }
    
    func top() {
        if self.stack.isEmpty {
            print(-1)
        } else {
            print(self.stack.last!)
        }
    }
}

var stack:Stack<Int> = Stack<Int>()
let numOfInstructions = Int(readLine()!)!

for _ in 1...numOfInstructions {
    let instruction = readLine()!.split(separator: " ")
    switch instruction[0] {
    case "push" : stack.push(Int(instruction[1])!)
    case "pop" : stack.pop()
    case "size" : stack.size()
    case "empty" : stack.isEmpty()
    case "top" : stack.top()
    default:
        print("ERR")
    }
}

