import math

primeNumber = [True] * 246913

for i in range(2, 246914) :
    for j in range(2, int(math.ceil(math.sqrt(246913)))) :
        if i * j >= 246913 :
            break
        else :
            primeNumber[i*j] = False

primeNumber[0], primeNumber[1] = False, False

i = 1
counter = 0

while i != 0 :
    i = int(input())
    if i == 0 :
        break
    else :
        for j in range(i + 1, 2 * i + 1) :
            if primeNumber[j] == True :
                counter = counter + 1
        print(counter)
        counter = 0
