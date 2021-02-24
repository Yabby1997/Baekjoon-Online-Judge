import Foundation

var whitePaperCount = 0
var bluePaperCount = 0

func divideAndConquer(_ rowFrom: Int, _ rowTo: Int, _ colFrom: Int, _ colTo: Int) {
    let color = matrix[rowFrom][colFrom]

    if rowTo - rowFrom != 1{
        for row in rowFrom..<rowTo{
            for col in colFrom..<colTo {
                if matrix[row][col] != color {
                    divideAndConquer(rowFrom, (rowFrom + rowTo) / 2, colFrom, (colFrom + colTo) / 2)
                    divideAndConquer(rowFrom, (rowFrom + rowTo) / 2, (colFrom + colTo) / 2, colTo)
                    divideAndConquer((rowFrom + rowTo) / 2, rowTo, colFrom, (colFrom + colTo) / 2)
                    divideAndConquer((rowFrom + rowTo) / 2, rowTo, (colFrom + colTo) / 2, colTo)
                    return
                }
            }
        }
    }
    countColor(of: color)
    return
}

func countColor(of color: Int) {
    if color == 0 {
        whitePaperCount+=1
    }
    else {
        bluePaperCount+=1
    }
}

let size = Int(readLine()!)!
var matrix = [[Int]]()

for _ in 0..<size {
    matrix.append(readLine()!.split(separator: " ").map({Int(String($0))!}))
}

divideAndConquer(0, size, 0, size)

print(whitePaperCount)
print(bluePaperCount)