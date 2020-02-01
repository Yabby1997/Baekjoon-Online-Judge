import math

primeNumber = [True] * 1000001

for i in range(2, 1000002) :
    for j in range(2, int(math.ceil(math.sqrt(1000001)))) :
        if i * j >= 1000001 :
            break
        else :
            primeNumber[i*j] = False

primeNumber[0], primeNumber[1] = False, False

fromA, toB = map(int, input().split())

for i in range(fromA, toB + 1) :
    if primeNumber[i] == True :
        print(i)
