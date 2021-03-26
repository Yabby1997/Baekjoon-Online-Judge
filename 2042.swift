import Foundation

let input = readLine()!.split(separator: " ").map({Int(String($0))!})
let numOfNumbers = input[0]
let numOfCommands = input[1] + input[2]

var numbers: [Int64] = [0]

for _ in 0..<numOfNumbers {
    numbers.append(Int64(readLine()!)!)
}

var segmentTree: [Int64] = Array(repeating: 0, count: 1 << Int(ceil(log2(Double(numOfNumbers))) + 1) - 1)
let _ = initTree(currentFrom: 1, currentTo: numOfNumbers, currentIndex: 0)

for _ in 0..<numOfCommands {
    let command = readLine()!.split(separator: " ").map({Int64(String($0))!})
    
    if command[0] == 1 {
        let target = Int(command[1])
        let difference = command[2] - numbers[target]
        numbers[target] = command[2]
        update(currentFrom: 1, currentTo: numOfNumbers, target: target, currentIndex: 0, difference: difference)
    } else if command[0] == 2 {
        let from = Int(command[1])
        let to = Int(command[2])
        print(sum(from: from, to: to, currentFrom: 1, currentTo: numOfNumbers, currentIndex: 0))
    }
}

func leftChild(of index: Int) -> Int {
    return index * 2 + 1
}

func rightChild(of index: Int) -> Int {
    return index * 2 + 2
}

func initTree(currentFrom: Int, currentTo: Int, currentIndex: Int) -> Int64 {
    if currentFrom == currentTo {
        segmentTree[currentIndex] = numbers[currentFrom]
    } else {
        let mid = (currentFrom + currentTo) / 2
        segmentTree[currentIndex] = initTree(currentFrom: currentFrom, currentTo: mid, currentIndex: leftChild(of: currentIndex)) + initTree(currentFrom: mid + 1, currentTo: currentTo, currentIndex: rightChild(of: currentIndex))
    }
    return segmentTree[currentIndex]
}

func sum(from: Int, to: Int, currentFrom: Int, currentTo: Int, currentIndex: Int) -> Int64 {
    if from <= currentFrom && currentTo <= to {
        return segmentTree[currentIndex]
    } else if currentTo < from || currentFrom > to {
        return 0
    } else {
        let mid = (currentFrom + currentTo) / 2
        return sum(from: from, to: to, currentFrom: currentFrom, currentTo: mid, currentIndex: leftChild(of: currentIndex)) + sum(from: from, to: to, currentFrom: mid + 1, currentTo: currentTo, currentIndex: rightChild(of: currentIndex))
    }
}

func update(currentFrom: Int, currentTo: Int, target: Int, currentIndex: Int, difference: Int64) {
    if currentFrom <= target && target <= currentTo {
        segmentTree[currentIndex] += difference
        
        if currentFrom != currentTo {
            let mid = (currentFrom + currentTo) / 2
            update(currentFrom: currentFrom, currentTo: mid, target: target, currentIndex: leftChild(of: currentIndex), difference: difference)
            update(currentFrom: mid + 1, currentTo: currentTo, target: target, currentIndex: rightChild(of: currentIndex), difference: difference)
        }
    }
}

