import Foundation

func solution() {
    guard let input = readLine(), let numberOfTests = Int(input) else { return }
    for _ in 0..<numberOfTests {
        let _ = readLine()
        guard let coins = (readLine()?.split(separator: " ").compactMap { Int(String($0)) }), let input = readLine(), let target = Int(input) else { return }
        var dp = Array(repeating: 0, count: target + 1)
        
        for coin in coins {
            guard coin <= target else { continue }
            dp[coin] += 1
            guard coin + 1 <= target else { continue }
            for i in coin + 1...target { dp[i] += dp[i - coin] }
        }
        print(dp[target])
    }
}

solution()

