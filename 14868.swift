import Foundation

class Area {
    var x: Int
    var y: Int
    
    init(x: Int, y: Int) {
        self.x = x
        self.y = y
    }
}

struct Queue<T> {
    var list: [T]
    
    func size() -> Int {
        return list.count
    }
    
    func isEmpty() -> Bool {
        return size() == 0
    }
    
    func peak() -> T? {
        if isEmpty() {
            return nil
        } else {
            return list[0]
        }
    }
    
    mutating func enqueue(_ element: T) {
        list.append(element)
    }
    
    mutating func dequeue() -> T? {
        if isEmpty() {
            return nil
        } else {
            return list.removeFirst()
        }
    }
}

let xDirections = [1, -1, 0, 0]
let yDirections = [0, 0, 1, -1]

let input = readLine()!.split(separator: " ").map({Int(String($0))!})
let width = input[0]
let numOfCivs = input[1]
var remainingCivs = numOfCivs
var civQueue = Array(repeating: Queue<Area>(list: []), count: numOfCivs)
var map = Array(repeating: Array(repeating: -1, count: width + 1), count: width + 1)
var civGroups = Array(repeating: -1, count: numOfCivs)
var turns = 0
var numOfTry = 0
var currentTry = 0

for civilizationNumber in 0..<numOfCivs {
    let civilizationInfo = readLine()!.split(separator: " ").map({Int(String($0))!})
    let x = civilizationInfo[0]
    let y = civilizationInfo[1]
    civQueue[civilizationNumber].enqueue(Area(x: x, y: y))
    map[x][y] = civilizationNumber
    civGroups[civilizationNumber] = civilizationNumber
}

while remainingCivs != 1 {
    for number in 0..<numOfCivs {
        BFS(civilization : number)
    }
    turns += 1
}

print(turns)


func BFS(civilization number: Int) {
    numOfTry = civQueue[number].size()
    currentTry = 0
    while currentTry < numOfTry {
        currentTry += 1
        let currentCivilizationNumber = civGroups[number]
        let currentArea = civQueue[number].dequeue()!
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
            let civilizationNumberOfNextArea = findParentCivilization(civilization: map[nextX][nextY])
            if civilizationNumberOfNextArea == currentCivilizationNumber{
                continue
            }
            
            // 미개한 문명이라면 문명을 퍼뜨리고, 미개하지 않으면서 다른 문명이면 문명을 합치고 해당 문명 큐의것을 내 큐로 가져온다.
            if civilizationNumberOfNextArea == -1 {
                civQueue[number].enqueue(Area(x: nextX, y: nextY))
                map[nextX][nextY] = currentCivilizationNumber
                searchAndMerge(number: currentCivilizationNumber, x: nextX, y: nextY)
            }
        }
    }
}

func findParentCivilization(civilization number: Int) -> Int {
    if number == -1 || civGroups[number] == number {
        return number
    } else {
        return findParentCivilization(civilization: civGroups[number])
    }
}

func searchAndMerge(number: Int, x: Int, y: Int) {
    for direction in 0..<xDirections.count {
        let nextX = x + xDirections[direction]
        let nextY = y + yDirections[direction]
        
        // 범위 밖이면 건너뛴다.
        if nextX < 1 || nextX > width || nextY < 1 || nextY > width {
            continue
        }
        
        // 범위 내지만 동일 문명이면 건너뛴다.
        let civilizationNumberOfNextArea = findParentCivilization(civilization: map[nextX][nextY])
        if civilizationNumberOfNextArea == number{
            continue
        }
        
        // 다른 문명이면 문명을 합치고 해당 문명 큐의것을 내 큐로 가져온다.
        if civilizationNumberOfNextArea != -1 {
            remainingCivs -= 1
            civGroups[civilizationNumberOfNextArea] = number
        }
    }
}

