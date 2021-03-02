import Foundation

struct EdgeData: Comparable {
    let to: Int
    let cost: Int
    
    static func < (lhs: EdgeData, rhs: EdgeData) -> Bool {
        lhs.cost < rhs.cost
    }
}

class PriorityQueue<T> {
    var heap: [T]
    let priority: (T, T) -> Bool
    
    init(heap: [T], priority: @escaping (T, T) -> Bool) {
        self.heap = heap
        self.priority = priority
        buildHeap()
    }
    
    func isEmpty() -> Bool {
        return heap.isEmpty
    }
    
    func size() -> Int {
        return heap.count
    }
    
    func leftChildIndex(of index: Int) -> Int {
        return index * 2 + 1
    }
    
    func rightChildIndex(of index: Int) -> Int {
        return index * 2 + 2
    }
    
    func parentIndex(of index: Int) -> Int {
        return (index - 1) / 2
    }
    
    func enqueue(_ element: T) {
        var currentIndex = heap.count
        heap.append(element)
        
        while currentIndex != 0 {
            let parent = parentIndex(of: currentIndex)
            if priority(heap[currentIndex], heap[parent]) {
                heap.swapAt(currentIndex, parent)
                currentIndex = parent
            } else {
                break
            }
        }
    }
    
    func dequeue() -> T?{
        if isEmpty() {
            return nil
        } else {
            heap.swapAt(0, heap.count - 1)
            let target = heap.removeLast()
            heapify(at: 0)
            return target
        }
    }
    
    func heapify(at index: Int) {
        var targetIndex = rightChildIndex(of: index)
        let leftIndex = leftChildIndex(of: index)
        
        if targetIndex < heap.count {
            if priority(heap[leftIndex], heap[targetIndex]) {
                targetIndex = leftIndex
            }
        } else if leftIndex < heap.count {
            targetIndex = leftIndex
        } else {
            return
        }
        
        if priority(heap[targetIndex], heap[index]) {
            heap.swapAt(targetIndex, index)
            heapify(at: targetIndex)
        } else {
            return
        }
    }
    
    func buildHeap() {
        for eachParent in (0..<(heap.count / 2)).reversed() {
            heapify(at: eachParent)
        }
    }
}

var adjacencyList = [[EdgeData]]()
var numOfVertices = 0
var numOfEdges = 0
var givenNumOfBlueEdges = 0

while true {
    let input = readLine()!.split(separator: " ").map({Int(String($0))!})
    numOfVertices = input[0]
    numOfEdges = input[1]
    givenNumOfBlueEdges = input[2]
    
    adjacencyList = Array(repeating: [EdgeData](), count: numOfVertices + 1)
    
    if numOfVertices == 0 && numOfVertices == numOfEdges && numOfEdges == givenNumOfBlueEdges {
        break
    }
    
    for _ in 0..<numOfEdges {
        let eachEdgeInfo = readLine()!.split(separator: " ").map({String($0)})
        let colorOfEdge = eachEdgeInfo[0]
        let from = Int(eachEdgeInfo[1])!
        let to = Int(eachEdgeInfo[2])!
        
        if colorOfEdge == "B" {
            adjacencyList[from].append(EdgeData(to: to, cost: 1))
            adjacencyList[to].append(EdgeData(to: from, cost: 1))
        } else {
            adjacencyList[from].append(EdgeData(to: to, cost: 0))
            adjacencyList[to].append(EdgeData(to: from, cost: 0))
        }
    }
    
    let minBlueEdges = prim(priority: <)
    let maxBlueEdges = prim(priority: >)
    
    if minBlueEdges <= givenNumOfBlueEdges && givenNumOfBlueEdges <= maxBlueEdges {
        print(1)
    } else {
        print(0)
    }
}

func prim(priority: @escaping (EdgeData, EdgeData) -> Bool) -> Int {
    let priorityQueue = PriorityQueue<EdgeData>(heap: [], priority: priority)
    var visited = Array(repeating: false, count: numOfVertices + 1)
    var totalCost = 0
    
    visited[1] = true
    for i in 0..<adjacencyList[1].count {
        priorityQueue.enqueue(adjacencyList[1][i])
    }
    
    while !priorityQueue.isEmpty() {
        let currentEdge = priorityQueue.dequeue()!
        let to = currentEdge.to
        let cost = currentEdge.cost
        
        if visited[to] {
            continue
        } else {
            visited[to] = true
            for i in 0..<adjacencyList[to].count {
                priorityQueue.enqueue(adjacencyList[to][i])
            }
            totalCost += cost
        }
    }
    
    for index in 1..<visited.count {
        if !visited[index] {
            return 1000000
        }
    }
    return totalCost
}

