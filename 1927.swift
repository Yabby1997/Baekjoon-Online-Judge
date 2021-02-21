import Foundation

struct PriorityQueue<T> {
    var elements : [T] = []
    let priorityFunc : (T, T) ->  Bool
    
    init(elements: [T], priorityFunc: @escaping (T, T) -> Bool) {
        self.elements = elements
        self.priorityFunc = priorityFunc
        buildHeap()
    }
    
    func left(of index: Int) -> Int {
        return index * 2  + 1
    }
    
    func right(of index: Int) -> Int {
        return index * 2 + 2
    }
    
    func parent(of index: Int) -> Int {
        return (index - 1) / 2
    }
    
    mutating func push(_ element: T) {
        elements.append(element)
        var currentIndex = elements.count - 1
        while currentIndex != 0 {
            let parentIndex = parent(of: currentIndex)
            if priorityFunc(elements[currentIndex], elements[parentIndex]) {
                elements.swapAt(currentIndex, parentIndex)
                currentIndex = parentIndex
            }
            else {
                break
            }
        }
    }
    
    mutating func pop() -> T? {
        if elements.count == 0 {
            return nil
        } else {
            let target = elements[0]
            let last = elements.popLast()
            if elements.count != 0 {
                elements[0] = last!
                heapify(at: 0)
            }
            return target
        }
    }
    
    mutating func heapify(at index: Int) {
        let leftIndex = left(of: index)
        let rightIndex = right(of: index)
        var indexToBeSwapped = rightIndex
        if rightIndex < elements.count {
            if priorityFunc(elements[leftIndex], elements[rightIndex]) {
                indexToBeSwapped = leftIndex
            }
        } else if leftIndex < elements.count {
            indexToBeSwapped = leftIndex
        } else {
            return
        }
        if priorityFunc(elements[indexToBeSwapped], elements[index]) {
            elements.swapAt(index, indexToBeSwapped)
            heapify(at: indexToBeSwapped)
        } else {
            return
        }
    }
    
    mutating func buildHeap() {
        for eachParent in (0 ..< elements.count / 2).reversed() {
            heapify(at: eachParent)
        }
    }
}

var pq = PriorityQueue(elements: [Int](), priorityFunc: <)

let numOfOps = Int(readLine()!)!

for _ in 0..<numOfOps {
    let input = Int(readLine()!)!
    if input == 0 {
        let result = pq.pop()
        if result == nil {
            print(0)
        } else {
            print(result!)
        }
    } else {
        pq.push(input)
    }
}
