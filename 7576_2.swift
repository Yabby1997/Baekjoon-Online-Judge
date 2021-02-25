import Foundation

class Node<T> {
    var value: T
    var next: Node<T>?

    init(value: T, next: Node<T>?) {
        self.value = value
        self.next = next
    }

    func getValue() -> T {
        return self.value
    }

    func getNext() -> Node<T>? {
        return self.next
    }

    func setNext(_ next: Node<T>?) {
        self.next = next!
    }
}

class Queue<T> {
    var head: Node<T>?
    var tail: Node<T>?
    var size = 0

    init() {
        self.head = nil
        self.tail = nil
    }

    func isEmpty() -> Bool {
        return self.size == 0 ? true : false
    }

    func enqueue(_ element: T) {
        let newNode = Node(value: element, next: nil)
        if self.size == 0 {
            self.head = newNode
            self.tail = newNode
        } else {
            self.tail!.setNext(newNode)
            self.tail! = self.tail!.getNext()!
        }
        self.size += 1
    }

    func dequeue() -> T? {
        if self.isEmpty() {
            return nil
        } else {
            let target = self.head!.getValue()
            if let nextNode = self.head!.getNext() {
                self.head = nextNode
            }
            self.size -= 1
            return target
        }
    }
    
    func show() {
        for _ in 0..<self.size {
            print(self.dequeue()!)
        }
    }
}

struct Tomato {
    let rowPos: Int
    let colPos: Int
}

let rowDirection = [-1, 1, 0, 0]
let colDirection = [0, 0, -1, 1]

let size = readLine()!.split(separator: " ").map({Int(String($0))!})
let row = size[1]
let col = size[0]

var tomatoes = Array(repeating: Array(repeating: 0, count:col), count: row)
var tomatoQueue = Queue<Tomato>()

for i in 0..<row {
    let eachRow = readLine()!.split(separator: " ").map({Int(String($0))!})
    for j in 0..<col {
        if eachRow[j] == 1 {
            tomatoQueue.enqueue(Tomato(rowPos: i, colPos: j))
        }
        tomatoes[i][j] = eachRow[j]
    }
}

BFS()
printResult()

func printResult() {
    var day = 0
    for i in 0..<row {
        for j in 0..<col {
            if tomatoes[i][j] > day {
                day = tomatoes[i][j]
            } else if tomatoes[i][j] == 0 {
                print(-1)
                return
            }
        }
    }
    print(day - 1)
}

func BFS() {
    while !tomatoQueue.isEmpty() {
        let tomato = tomatoQueue.dequeue()!
        let originalRow = tomato.rowPos
        let originalCol = tomato.colPos
        for direction in 0...3 {
            let targetRow = originalRow + rowDirection[direction]
            let targetCol = originalCol + colDirection[direction]
            if targetRow >= 0 && targetRow < row && targetCol >= 0 && targetCol < col && tomatoes[targetRow][targetCol] == 0{
                tomatoes[targetRow][targetCol] = tomatoes[originalRow][originalCol] + 1
                tomatoQueue.enqueue(Tomato(rowPos: targetRow, colPos: targetCol))
            }
        }
    }
}

