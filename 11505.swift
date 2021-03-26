import Foundation

let operand: Int64 = 1_000_000_007

let input = readLine()!.split(separator: " ").map({Int(String($0))!})
let numOfNumbers = input[0]
let numOfCommands = input[1] + input[2]

var numbers: [Int64] = [0]

for _ in 0..<numOfNumbers {
    numbers.append(Int64(readLine()!)!)
}

var segmentTree: [Int64] = Array(repeating: 0, count: (1 << Int(ceil(log2(Double(numOfNumbers))) + 1)) - 1)
let _ = buildTree(from: 1, to: numOfNumbers, node: 0)

for _ in 0..<numOfCommands {
    let command = readLine()!.split(separator: " ").map({Int64(String($0))!})
    
    if command[0] == 1 {
        let target = Int(command[1])
        let newValue = command[2]
        let _ = update(target: target, newValue: newValue, from: 1, to: numOfNumbers, node: 0)
    } else if command[0] == 2 {
        let rangeFrom = Int(command[1])
        let rangeTo = Int(command[2])
        print(mul(rangeFrom: rangeFrom, rangeTo: rangeTo, from: 1, to: numOfNumbers, node: 0))
    }
}


func leftChild(of node: Int) -> Int {
    return node * 2 + 1
}

func rightChild(of node: Int) -> Int {
    return node * 2 + 2
}

func buildTree(from: Int, to: Int, node: Int) -> Int64 {
    if from == to {
        segmentTree[node] = numbers[from]
    } else {
        let mid = (from + to) / 2
        let left = buildTree(from: from, to: mid, node: leftChild(of: node))
        let right = buildTree(from: mid + 1, to: to, node: rightChild(of: node))
        segmentTree[node] = (left * right) % operand
    }
    return segmentTree[node]
}

func mul(rangeFrom: Int, rangeTo: Int, from: Int, to: Int, node: Int) -> Int64 {
    if rangeFrom > to || rangeTo < from {
        return 1
    } else if rangeFrom <= from && to <= rangeTo {
        return segmentTree[node]
    } else {
        let mid = (from + to) / 2
        let left = mul(rangeFrom: rangeFrom, rangeTo: rangeTo, from: from, to: mid, node: leftChild(of: node))
        let right = mul(rangeFrom: rangeFrom, rangeTo: rangeTo, from: mid + 1, to: to, node: rightChild(of: node))
        return (left * right) % operand
    }
}

func update(target: Int, newValue: Int64, from: Int, to: Int, node: Int) -> Int64 {
    if from == to {
        if from == target {
            segmentTree[node] = newValue
            numbers[from] = newValue
        }
        return segmentTree[node]
    } else if from <= target && target <= to {
        let mid = (from + to) / 2
        let left = update(target: target, newValue: newValue, from: from, to: mid, node: leftChild(of: node))
        let right = update(target: target, newValue: newValue, from: mid + 1, to: to, node: rightChild(of: node))
        segmentTree[node] = (left * right) % operand
    }
    return segmentTree[node]
}

