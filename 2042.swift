import Foundation

struct SegmentTree {
    var numbers: [Int64]
    var tree: [Int64]
    
    init(numbers: [Int64]) {
        self.numbers = numbers
        self.tree = Array(repeating: 0, count: 1 << (Int(ceil(log2(Double(numbers.count)))) + 1))
        let _ = buildTree(from: 0, to: numbers.count - 1, index: 0)
    }
    
    func leftChild(of index: Int) -> Int {
        return index * 2 + 1
    }
    
    func rightChild(of index: Int) -> Int {
        return index * 2 + 2
    }
    
    mutating func buildTree(from: Int, to: Int, index: Int) -> Int64 {
        if from == to {
            tree[index] = numbers[from]
        } else {
            let mid = (to + from) / 2
            tree[index] = buildTree(from: from, to: mid, index: leftChild(of: index)) + buildTree(from: mid + 1, to: to, index: rightChild(of: index))
        }
        return tree[index]
    }
    
    func sum(queryFrom: Int64, queryTo: Int64, currentFrom: Int, currentTo: Int, index: Int) -> Int64 {
        if queryFrom <= currentFrom && currentTo <= queryTo {
            return tree[index]
        } else if currentFrom > queryTo || currentTo < queryFrom {
            return 0
        } else {
            let mid = (currentTo + currentFrom) / 2
            return sum(queryFrom: queryFrom, queryTo: queryTo, currentFrom: currentFrom, currentTo: mid, index: index * 2 + 1) + sum(queryFrom: queryFrom, queryTo: queryTo, currentFrom: mid + 1, currentTo: currentTo, index: index * 2 + 2)
        }
    }
    
    mutating func update(from: Int, to: Int, index: Int, target: Int, new: Int64) {
        if target < from || target > to {
            return
        }
        let difference = new - numbers[target]
        tree[index] += difference
        if from != to {
            let mid = (from + to) / 2
            update(from: from, to: mid, index: leftChild(of: index), target: target, new: new)
            update(from: mid + 1, to: to, index: rightChild(of: index), target: target, new: new)
        }
        else {
            numbers[from] += difference
        }
    }
}

var numbers: [Int64] = []
let input = readLine()!.split(separator: " ").map({Int(String($0))!})
let numOfNumbers = input[0]
let numOfActions = input[1] + input[2]

for _ in 0..<numOfNumbers {
    numbers.append(Int64(readLine()!)!)
}

var segmentTree = SegmentTree(numbers: numbers)

for _ in 0..<numOfActions {
    let commands = readLine()!.split(separator: " ").map({Int64(String($0))!})

    if commands[0] == 1 {
        segmentTree.update(from: 0, to: numOfNumbers - 1, index: 0, target: Int(commands[1]) - 1, new: commands[2])
    } else {
        print(segmentTree.sum(queryFrom: commands[1] - 1, queryTo: commands[2] - 1, currentFrom: 0, currentTo: numOfNumbers - 1, index: 0))
    }
}
