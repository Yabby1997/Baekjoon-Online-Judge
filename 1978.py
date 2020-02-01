numOfCases = int(input())
cases = map(int, input().split())
counter = 0

for each in cases :
    j = 2
    while True :
        if each == 1:
            #print("@ 1 is NOT prime")
            break
        elif each == j:
            counter = counter + 1
            #print("@ %d devided by itself. it is prime" %(each))
            break
        elif each % j == 0:
            #print("@ %d devided like %d x %d. it is NOT prime" %(each, j, each/j))
            break
        elif j > each :
            #print("@ %d is NOT prime" %(each))
            break
        j = j + 1
print(counter)
