import Foundation

struct Area {
    var x: Int
    var y: Int
}

struct Queue<T> {
    var list: [T]
    var from: Int
    var to: Int
    
    func size() -> Int {
        return to - from
    }
    
    func isEmpty() -> Bool {
        return size() == 0
    }
    
    mutating func enqueue(_ element: T) {
        list.append(element)
        to += 1
    }
    
    mutating func dequeue() -> T? {
        if isEmpty() {
            return nil
        } else {
            let target = list[from]
            from += 1
            return target
        }
    }
}

let xDirections = [1, -1, 0, 0]
let yDirections = [0, 0, 1, -1]

let input = readLine()!.split(separator: " ").map({Int(String($0))!})
let width = input[0]
let numOfGivenCivilizations = input[1]
var numOfCurrentCivilizations = numOfGivenCivilizations
var civilizations = Array(repeating: Queue<Area>(list: [], from: 0, to: 0), count: numOfGivenCivilizations)
var civilizationMap = Array(repeating: Array(repeating: -1, count: width + 1), count: width + 1)
var civilizationsMergedTo = Array(repeating: -1, count: numOfGivenCivilizations)
var takenTurns = 0

for civilizationNumber in 0..<numOfGivenCivilizations {
    let civilizationInfo = readLine()!.split(separator: " ").map({Int(String($0))!})
    let x = civilizationInfo[0]
    let y = civilizationInfo[1]
    civilizations[civilizationNumber].enqueue(Area(x: x, y: y))
    civilizationMap[x][y] = civilizationNumber
    civilizationsMergedTo[civilizationNumber] = civilizationNumber
}

while numOfCurrentCivilizations != 1 {
    for number in 0..<numOfGivenCivilizations {
        BFS(civilization : number)
    }
    takenTurns += 1
}

print(takenTurns)


func BFS(civilization number: Int) {
    var numOfTry = civilizations[number].size()
    var currentTry = 0
    while currentTry < numOfTry {
        currentTry += 1
        let currentArea = civilizations[number].dequeue()!
        let x = currentArea.x
        let y = currentArea.y
        for direction in 0..<xDirections.count {
            let nextX = x + xDirections[direction]
            let nextY = y + yDirections[direction]
            
            // 범위 밖이면 건너뛴다.
            if nextX < 1 || nextX > width || nextY < 1 || nextY > width {
                continue
            }
            
            // 범위 내지만 동일 문명이면 건너뛴다.
            let civilizationNumberOfNextArea = findParentCivilization(civilization: civilizationMap[nextX][nextY])
            if civilizationNumberOfNextArea == number{
                continue
            }
            
            // 미개한 문명이라면 문명을 퍼뜨리고, 미개하지 않으면서 다른 문명이면 문명을 합치고 해당 문명 큐의것을 내 큐로 가져온다.
            if civilizationNumberOfNextArea == -1 {
                civilizations[number].enqueue(Area(x: nextX, y: nextY))
                civilizationMap[nextX][nextY] = number
            } else {
                numOfCurrentCivilizations -= 1
                civilizationsMergedTo[civilizationNumberOfNextArea] = number
                while !civilizations[civilizationNumberOfNextArea].isEmpty() {
                    numOfTry += 1
                    civilizations[number].enqueue(civilizations[civilizationNumberOfNextArea].dequeue()!)
                }
            }
        }
    }
}

func findParentCivilization(civilization number: Int) -> Int {
    if number == -1 || civilizationsMergedTo[number] == number {
        return number
    } else {
        return findParentCivilization(civilization: civilizationsMergedTo[number])
    }
}


