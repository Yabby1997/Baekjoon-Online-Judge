import Foundation

struct Queue<T> {
	var list: [T]
	var from = 0
	var to = 0

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
		}
		else {
			let target = list[from]
			from += 1
			return target
		}
	}
}

struct Position {
	let rowPos: Int
	let colPos: Int
}

let rowDirection = [1, -1, 0, 0]
let colDirection = [0, 0, 1, -1]
let size = readLine()!.split(separator: " ").map({Int(String($0))!})
let row = size[0]
let col = size[1]
var maze = Array(repeating: [Int](), count: row)
var pathQueue = Queue<Position>(list: [], from: 0, to: 0)

for i in 0..<row {
	let eachRow = Array(readLine()!)
	maze[i] = eachRow.map({Int(String($0))!})
}

pathQueue.enqueue(Position(rowPos: 0, colPos: 0))
BFS()
print(maze[row - 1][col - 1])

func BFS() {
	while !pathQueue.isEmpty() {
		let currentPosition = pathQueue.dequeue()!
		let currentRow = currentPosition.rowPos
		let currentCol = currentPosition.colPos
		for direction in 0..<rowDirection.count {
			let nextRow = currentRow + rowDirection[direction]
			let nextCol = currentCol + colDirection[direction]
			if nextRow >= 0 && nextRow < row && nextCol >= 0 && nextCol < col && maze[nextRow][nextCol] == 1 {
				maze[nextRow][nextCol] = maze[currentRow][currentCol] + 1
				pathQueue.enqueue(Position(rowPos: nextRow, colPos: nextCol))
			}
		}
	}
}