import Foundation

struct PriorityQueue<T> {
    var heap : [T] = []
    let getPriority : (T, T) ->  Bool
    
    init(elements: [T], getPriority: @escaping (T, T) -> Bool) {
        self.heap = elements
        self.getPriority = getPriority
        buildHeap()
    }
    
    func getLeftChildIndex(of index: Int) -> Int {
        return index * 2  + 1
    }
    
    func getRightChildIndex(of index: Int) -> Int {
        return index * 2 + 2
    }
    
    func getParentIndex(of index: Int) -> Int {
        return (index - 1) / 2
    }
    
    mutating func enqueue(_ element: T) {
        heap.append(element)
        var currentIndex = heap.count - 1
        while currentIndex != 0 {
            let parentIndex = getParentIndex(of: currentIndex)
            if getPriority(heap[currentIndex], heap[parentIndex]) {
                heap.swapAt(currentIndex, parentIndex)
                currentIndex = parentIndex
            }
            else {
                break
            }
        }
    }
    
    mutating func dequeue() -> T? {
        if heap.count == 0 {
            return nil
        } else {
            let target = heap[0]
            let last = heap.popLast()
            if heap.count != 0 {
                heap[0] = last!
                heapify(at: 0)
            }
            return target
        }
    }
    
    mutating func heapify(at index: Int) {
        let left = getLeftChildIndex(of: index)
        let right = getRightChildIndex(of: index)
        var target = right
        if right < heap.count {
            if getPriority(heap[left], heap[right]) {
                target = left
            }
        } else if left < heap.count {
            target = left
        } else {
            return
        }
        if getPriority(heap[target], heap[index]) {
            heap.swapAt(index, target)
            heapify(at: target)
        } else {
            return
        }
    }
    
    mutating func buildHeap() {
        for eachParent in (0 ..< heap.count / 2).reversed() {
            heapify(at: eachParent)
        }
    }
    
    func isEmpty() -> Bool {
        return heap.isEmpty
    }
}

struct EdgeData: Comparable{
    static func < (lhs: EdgeData, rhs: EdgeData) -> Bool {
        lhs.cost < rhs.cost
    }
    
    let to: Int
    let cost: Int
}

let INF = 5000000
let input = readLine()!.split(separator: " ").map({Int(String($0))!})
let numOfVertices = input[0]
let numOfEdges = input[1]
let startingVertex = Int(readLine()!)!

var adjacencyList = Array(repeating: [(Int, Int)](), count: numOfVertices + 1)
var priorityQueue = PriorityQueue<EdgeData>(elements: [EdgeData](), getPriority: <)
var costs = Array(repeating: INF, count: numOfVertices + 1)

func printResult() {
    for i in 1..<costs.count {
        let cost = costs[i]
        if cost == INF {
            print("INF")
        }
        else {
            print(cost)
        }
    }
}

for _ in 0..<numOfEdges {
    let input = readLine()!.split(separator: " ").map({Int(String($0))!})
    let from = input[0]
    let to = input[1]
    let cost = input[2]
    
    adjacencyList[from].append((to, cost))
}

costs[startingVertex] = 0
priorityQueue.enqueue(EdgeData(to: startingVertex, cost: 0))

while !priorityQueue.isEmpty() {
    let current = priorityQueue.dequeue()!
    if costs[current.to] < current.cost {
        continue
    }
    for next in adjacencyList[current.to] {
        let newCost = next.1 + costs[current.to]
        if newCost < costs[next.0] {
            costs[next.0] = newCost
            priorityQueue.enqueue(EdgeData(to: next.0, cost: newCost))
        }
    }
}

printResult()
