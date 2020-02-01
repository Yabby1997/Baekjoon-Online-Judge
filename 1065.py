def checkNumber(givenNumber):
    counter = 0
    for i in range(givenNumber):
        each = i + 1                                            #i starts from 0 
        j = int(each/1000)
        k = int((each-j*1000)/100)
        m = int((each-j*1000-k*100)/10)a
        n = int(each-j*1000-k*100-m*10)
        if j == 0 and k == 0:   counter = counter + 1
        elif j == 0 and k-m == m-n:  counter = counter + 1
    return counter
    
inputNumber = int(input())

if inputNumber < 1 or inputNumber > 1000:   sys.exit()
else :  print(checkNumber(inputNumber))
