import Foundation

struct EdgeData: Comparable {
    var from: Int
    var to: Int
    var cost: Int
    
    static func < (lhs: EdgeData, rhs: EdgeData) -> Bool {
        lhs.cost < rhs.cost
    }
}

struct PriorityQueue<T> {
    var heap: [T]
    var priority: (T, T) -> Bool
    
    init(heap: [T], priority: @escaping (T, T) -> Bool) {
        self.heap = heap
        self.priority = priority
        buildHeap()
    }
    
    func getLeftChildIndex(of index: Int) -> Int {
        return index * 2 + 1
    }
    
    func getRightChildIndex(of index: Int) -> Int {
        return index * 2 + 2
    }
    
    func getParentIndex(of index: Int) -> Int {
        return (index - 1) / 2
    }
    
    func isEmpty() -> Bool {
        return heap.isEmpty
    }
    
    mutating func enqueue(_ element: T) {
        var currentIndex = heap.count
        heap.append(element)
        
        while currentIndex != 0 {
            let parentIndex = getParentIndex(of: currentIndex)
            if priority(heap[currentIndex], heap[parentIndex]) {
                heap.swapAt(currentIndex, parentIndex)
                currentIndex = parentIndex
            } else {
                break
            }
        }
    }
    
    mutating func dequeue() -> T? {
        if heap.isEmpty {
            return nil
        } else {
            heap.swapAt(0, heap.count - 1)
            let target = heap.removeLast()
            heapify(at: 0)
            return target
        }
    }
    
    mutating func heapify(at index: Int) {
        let leftChildIndex = getLeftChildIndex(of: index)
        var targetIndex = getRightChildIndex(of: index)
        
        if targetIndex < heap.count {
            if priority(heap[leftChildIndex], heap[targetIndex]) {
                targetIndex = leftChildIndex
            }
        } else if leftChildIndex < heap.count {
            targetIndex = leftChildIndex
        } else {
            return
        }
        if priority(heap[targetIndex], heap[index]) {
            heap.swapAt(targetIndex, index)
            heapify(at: targetIndex)
        }
    }
    
    mutating func buildHeap() {
        for eachParent in (0..<(heap.count / 2)).reversed() {
            heapify(at: eachParent)
        }
    }
}

let input = readLine()!.split(separator: " ").map({Int(String($0))!})
let numOfVertices = input[0]
let numOfEdges = input[1]

var grouped = Array(repeating: 0, count: numOfVertices + 1)
var edgeQueue = PriorityQueue<EdgeData>(heap: [], priority: <)
var currentGroup = 0
var totalCost = 0

for _ in 0..<numOfEdges {
    let input = readLine()!.split(separator: " ").map({Int(String($0))!})
    edgeQueue.enqueue(EdgeData(from: input[0], to: input[1], cost: input[2]))
}

while !edgeQueue.isEmpty() {
    let currentEdge = edgeQueue.dequeue()!
    let from = currentEdge.from
    let to = currentEdge.to
    let cost = currentEdge.cost
    if grouped[from] == grouped[to] {
        if grouped[from] == 0 {
            currentGroup += 1
            grouped[from] = currentGroup
            grouped[to] = currentGroup
            totalCost += cost
        } else {
            continue
        }
    } else {
        if grouped[from] == 0 {
            grouped[from] = grouped[to]
        } else if grouped[to] == 0 {
            grouped[to] = grouped[from]
        } else {
            let targetGroup = grouped[to]
            for i in 1..<grouped.count {
                if grouped[i] == targetGroup {
                    grouped[i] = grouped[from]
                }
            }
        }
        totalCost += cost
    }
}

print(totalCost)

