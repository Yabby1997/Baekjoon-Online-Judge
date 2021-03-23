import Foundation

let input = Int(readLine()!)!

var fiboArray = Array(repeating: 0, count: 50)
fiboArray[1] = 1
fiboArray[2] = 1

func getFibo(_ index: Int) -> Int {
    if index != 0 && fiboArray[index] == 0 {
        fiboArray[index] = getFibo(index - 1) + getFibo(index - 2)
        return fiboArray[index]
    } else {
        return fiboArray[index]
    }
}

print(getFibo(input))

