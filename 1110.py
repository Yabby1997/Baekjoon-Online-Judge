def getCycle(seedNumber, currentNumber, cycle):
    temp = [int(currentNumber/10), int(currentNumber%10)]
    nextNumber = int(temp[1]*10+(temp[0]+temp[1])%10)
    if(seedNumber == nextNumber) :  return cycle
    else :  return getCycle(seedNumber, nextNumber, cycle+1)

#you should define function first like C language
#in python, there's no return type or parameter type. (python is type-free)

initialNumber = int(input())

if(initialNumber > 99 or initialNumber < 0) :   sys.exit()
else :
    result = int(getCycle(initialNumber, initialNumber, 1))
    print(result)
