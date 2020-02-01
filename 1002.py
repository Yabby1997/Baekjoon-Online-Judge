def square(x) :
    return x * x

numOfCases = int(input())

for i in range(numOfCases) :
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    distance = square(x2 - x1) + square(y2 - y1)
    
    if distance == 0 and r1 == r2 :
        result = -1
    elif distance > square(r2 + r1) or distance < square(r1 - r2) :
        result = 0
    elif distance == square(r2 + r1) or distance == square(r1 - r2) :
        result = 1
    else :
        result = 2
    print(result)
