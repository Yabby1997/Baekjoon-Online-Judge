import Foundation

struct EdgeData {
    let from: Int
    let to: Int
    let cost: Int
}

let INF = 10_000_000
let input = readLine()!.split(separator: " ").map({Int(String($0))!})
let numOfVertices = input[0]
let numOfEdges = input[1]

var edges = [EdgeData]()
var distances = Array(repeating: INF, count: numOfVertices + 1)
distances[1] = 0

for _ in 0..<numOfEdges {
    let input = readLine()!.split(separator: " ").map({Int(String($0))!})
    edges.append(EdgeData(from: input[0], to: input[1], cost: input[2]))
}

for _ in 0..<numOfVertices {
    for edge in edges {
        if distances[edge.from] != INF && distances[edge.from] + edge.cost < distances[edge.to] {
            distances[edge.to] = distances[edge.from] + edge.cost
        }
    }
}

var isNegativeCycleExist = false

for edge in edges {
    if distances[edge.from] != INF && distances[edge.from] + edge.cost < distances[edge.to] {
        isNegativeCycleExist = true
        break
    }
}

if isNegativeCycleExist {
    print(-1)
} else {
    for vertex in 2...numOfVertices {
        let distance = distances[vertex]
        if distance == INF {
            print(-1)
        } else {
            print(distance)
        }
    }
}