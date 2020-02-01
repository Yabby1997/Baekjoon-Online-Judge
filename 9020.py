import math

primeNumber = [True] * 10001
primeNumber[0], primeNumber[1] = False, False

for i in range(2, 10002) :
    for j in range(2, int(math.sqrt(10001)) + 1) :
        if i * j >= 10001 :
            break
        else :
            primeNumber[i * j] = False

numOfCases = int(input())
for i in range(numOfCases) :
    inputNum = int(input())
    for j in range(int(inputNum/2), 1, -1) :                                    #RANGE(A, B, C), A = FROM, B = TO, C = DIFFERENCE
        if primeNumber[j] == True and primeNumber[inputNum - j] == True :
            print("%d %d" %(j, inputNum - j))
            break
