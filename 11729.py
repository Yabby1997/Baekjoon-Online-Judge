def solveHanoiRecursively(currentNum, departure, by, destination):
    if currentNum == 1 :
        print(departure, destination)
    else :
        solveHanoiRecursively(currentNum - 1, departure, destination, by)
        print(departure, destination)
        solveHanoiRecursively(currentNum - 1, by, departure, destination)

inputNum = int(input())
print(pow(2, inputNum) - 1)
solveHanoiRecursively(inputNum, 1, 2, 3)
