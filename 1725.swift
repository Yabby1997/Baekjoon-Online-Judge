import Foundation

let width = Int(readLine()!)!
var heights: [Int64] = [10000000000]
var best: Int64 = 0

for _ in 0..<width {
    heights.append(Int64(readLine()!)!)
}

var segmentTree: [Int] = Array(repeating: 0, count: (1 << Int((ceil(log2(Double(width))) + 1)) - 1))
let _ = buildTree(currentFrom: 1, currentTo: width, currentNode: 0)
divideAndConquer(from: 1, to: width)

print(best)

func leftChild(of node: Int) -> Int {
    return node * 2 + 1
}

func rightChild(of node: Int) -> Int {
    return node * 2 + 2
}

func buildTree(currentFrom: Int, currentTo: Int, currentNode: Int) ->  Int{
    if currentFrom == currentTo {
        segmentTree[currentNode] = currentFrom
    } else {
        let mid = (currentFrom + currentTo) / 2
        let leftMinIndex = buildTree(currentFrom: currentFrom, currentTo: mid, currentNode: leftChild(of: currentNode))
        let rightMinIndex = buildTree(currentFrom: mid + 1, currentTo: currentTo, currentNode: rightChild(of: currentNode))
        segmentTree[currentNode] = heights[leftMinIndex] <= heights[rightMinIndex] ? leftMinIndex : rightMinIndex
    }
    return segmentTree[currentNode]
}

func getMinHeightIndex(boundFrom: Int, boundTo: Int, currentFrom: Int, currentTo: Int, currentNode: Int) -> Int{
    if boundFrom > currentTo || boundTo < currentFrom  {
        return 0
    } else if boundFrom <= currentFrom && currentTo <= boundTo {
        return segmentTree[currentNode]
    } else {
        let mid = (currentFrom + currentTo) / 2
        let leftMinIndex = getMinHeightIndex(boundFrom: boundFrom, boundTo: boundTo, currentFrom: currentFrom, currentTo: mid, currentNode: leftChild(of: currentNode))
        let rightMinIndex = getMinHeightIndex(boundFrom: boundFrom, boundTo: boundTo, currentFrom: mid + 1, currentTo: currentTo, currentNode: rightChild(of: currentNode))
        return heights[leftMinIndex] < heights[rightMinIndex] ? leftMinIndex : rightMinIndex
    }
}

func divideAndConquer(from: Int, to: Int) {
    if from > to {
        return
    }
    let minHeightIndex = getMinHeightIndex(boundFrom: from, boundTo: to, currentFrom: 1, currentTo: width, currentNode: 0)
    let current = heights[minHeightIndex] * Int64(to - from + 1)
    if best < current {
        best = current
    }
    divideAndConquer(from: from, to: minHeightIndex - 1)
    divideAndConquer(from: minHeightIndex + 1, to: to)
}

