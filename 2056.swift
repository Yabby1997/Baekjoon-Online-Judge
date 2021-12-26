import Foundation

var dp = Array(repeating: 0, count: 10000)

func solution() {
    guard let input = readLine(), let numberOfTasks = Int(input) else { return }
    for job in 0..<numberOfTasks {
        guard let input = readLine() else { return }
        let inputNumbers = input.split(separator: " ").compactMap { Int($0) }
        if inputNumbers[1] == 0 {
            dp[job] = inputNumbers[0]
        } else {
            guard let max = (inputNumbers[2...].map { dp[$0 - 1] }.max { $0 < $1 }) else { return }
            dp[job] = max + inputNumbers[0]
        }
    }
    guard let answer = (dp.max { $0 < $1 }) else { return }
    print(answer)
}

solution()

