numA = int(input())
numB = int(input())

A = int(numB / 100)
B = int((numB - A * 100) / 10)
C = int(numB - A * 100 - B * 10)

print(numA * C)
print(numA * B)
print(numA * A)
print(numA * numB)
