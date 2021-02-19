import Foundation

struct Queue<T> {
    var queue: [T] = []
    
    mutating func push(_ element: T) {
        self.queue.append(element)
    }
    
    mutating func pop() -> T?{
        if queue.isEmpty {
            return nil
        } else {
            let target = queue.first!
            self.queue.remove(at: 0)
            return target
        }
    }
    
    func isEmpty() -> Bool{
        return queue.isEmpty
    }
}

let inputs = readLine()!.split(separator: " ")
let numOfVertices = Int(inputs[0])!
let numOfEdges = Int(inputs[1])!
let startingVertex = Int(inputs[2])!

var adjacencyList: [[Int]] = Array(repeating: [Int](), count: 1001)
var visited: [Bool] = Array(repeating: false, count: 1001)

input()
DFS(startingVertex)
clear()
BFS()


func input() {
    for _ in 1...numOfEdges {
        let input = readLine()!.split(separator: " ")
        let from = Int(input[0])!
        let to = Int(input[1])!
        adjacencyList[from].append(to)
        adjacencyList[to].append(from)
    }
    for i in 1...numOfVertices {
        adjacencyList[i].sort(by: <)
    }
}

func clear() {
    print()
    for i  in 1...numOfVertices {
        visited[i] = false
    }
}

func DFS(_ current: Int) {
    print(current, terminator: " ")
    visited[current] = true
    for element in adjacencyList[current] {
        if visited[element] {
            continue
        }
        DFS(element)
    }
}

func BFS() {
    var queue = Queue<Int>()
    queue.push(startingVertex)
    while !queue.isEmpty() {
        if let popped = queue.pop(){
            if visited[popped] {
                continue
            }
            print(popped, terminator: " ")
            visited[popped] = true
            for element in adjacencyList[popped] {
                if visited[element] {
                    continue
                }
                queue.push(element)
            }
        }
    }
}

