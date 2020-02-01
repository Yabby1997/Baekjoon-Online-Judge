def gdc(a, b):
    while b != 0:
        tmp = a % b
        a = b
        b = tmp
    return a
    
def lcm(a, b):
    return a * b / gdc(a, b)

def calculate(mX, mY, X, Y) :
    year = X
    while True :
        if mX > 40000 or mY > 40000 or X == 0 or Y ==0 or X > mX or Y > mY :
            year = -1
            break
        if year > lcm(mX, mY) :
            year = -1
            break
        if year % mY == 0 :
            yearY = mY
        else :
            yearY = year % mY
        if yearY == Y :
            break
        year = year + mX
    return year
        
numOfCases = int(input())
for i in range(numOfCases):
    mX, mY, X, Y = map(int, input().split())
    print(calculate(mX, mY, X, Y))
