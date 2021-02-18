import Foundation

let initial = Int(readLine()!)!
var num = initial
var a = 0
var b = 0
var cycle = 0

repeat {
    a = num / 10
    b = num % 10
    num = (num % 10) * 10 + (a + b) % 10
    cycle += 1
} while initial != num

print(cycle)

