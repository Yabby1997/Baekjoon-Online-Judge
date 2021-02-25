import Foundation

struct Queue<T> {
    var list: [T]
    var from = 0
    var to = 0

    func size() -> Int {
        return to - from
    }

    func isEmpty() -> Bool {
        return size() == 0 ? true : false
    }

    mutating func enqueue(_ element: T) {
        to += 1
        list.append(element)
    }

    mutating func dequeue() -> T? {
        if isEmpty() {
            return nil
        } else {
            let target = list[from]
            from += 1
            return target
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
var tomatoQueue = Queue<Tomato>(list: [], from: 0, to: 0)

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
