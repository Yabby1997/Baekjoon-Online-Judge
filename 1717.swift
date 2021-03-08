import Foundation

let input = readLine()!.split(separator: " ").map({Int(String($0))!})
let numOfVertices = input[0]
let numOfInputs = input[1]

var actualGroup = Array(repeating: -1, count: numOfVertices + 1)

for i in 0...numOfVertices {
    actualGroup[i] = i
}

for _ in 0..<numOfInputs {
    let eachCommand = readLine()!.split(separator: " ").map({Int(String($0))!})
    let command = eachCommand[0]
    let from = eachCommand[1]
    let to = eachCommand[2]
    
    if command == 0 {
        union(from, to)
    } else if command == 1 {
        isInSameGroup(from, to)
    }
}

func find(_ vertex: Int) -> Int {
    if actualGroup[vertex] == vertex {
        return vertex
    } else {
        actualGroup[vertex] = find(actualGroup[vertex])
        return actualGroup[vertex]
    }
}

func union(_ a: Int, _ b: Int) {
    let actualA = find(a)
    let actualB = find(b)
    
    if actualA != actualB {
        actualGroup[actualB] = actualA
    }
}

func isInSameGroup(_ a: Int, _ b: Int) {
    let actualA = find(a)
    let actualB = find(b)
    
    if actualA == actualB {
        print("YES")
        return
    }
    print("NO")
}

