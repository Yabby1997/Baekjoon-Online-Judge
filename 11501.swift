import Foundation

let numOfTests = Int(readLine()!)!
var prices: [Int] = []

for _ in 0..<numOfTests {
    let _ = readLine()
    prices = readLine()!.split(separator: " ").map({Int(String($0))!})
    
    var sum: Int64 = 0
    
    var maxIndex = prices.count - 1
    var cost = 0
    var numOfStocks = 0
    for index in (0..<prices.count).reversed() {
        if maxIndex == index {
            continue
        }
        if prices[maxIndex] < prices[index] {
            sum += Int64((numOfStocks * prices[maxIndex]) - cost)
            numOfStocks = 0
            cost = 0
            maxIndex = index
        } else {
            cost += prices[index]
            numOfStocks += 1
        }
    }
    
    sum += Int64((numOfStocks * prices[maxIndex]) - cost)
    
    print(sum)
    prices = []
}

