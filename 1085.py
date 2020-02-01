inputList = list(map(int, input().split()))

inputList[2] = inputList[2] - inputList[0]
inputList[3] = inputList[3] - inputList[1]

print(min(inputList))
