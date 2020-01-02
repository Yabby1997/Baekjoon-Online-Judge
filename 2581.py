a = int(input())
b = int(input())
minimum = 0
sumOfPrime = 0

for i in range(a, b+1):
    j = 2
    while True :
        if i == 1 :
            break
        elif i == j :
            if minimum == 0 :
                minimum = i
            sumOfPrime = sumOfPrime + i
        elif i % j == 0 :
            break
        elif j > i :
            break
        j = j + 1

if minimum == 0 :
    print(-1)
else :
    print(sumOfPrime)
    print(minimum)
