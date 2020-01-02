numOfCase = int(input())

for i in range(numOfCase):
    charIteration, inputString = input().split()        #SPLIT METHOD AUTOMATICALLY MAKE DATA TYPE INTO STRING
    for each in inputString:
        for i in range(int(charIteration)):
            print(each, end='')
    print()
