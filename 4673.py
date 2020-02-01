kaprekarArray = [0 for i in range(10100)]

def kaprekarFunc(seedNumber):
    j = int(seedNumber/1000)
    k = int((seedNumber-j*1000)/100)
    m = int((seedNumber-j*1000-k*100)/10)
    n = int(seedNumber-j*1000-k*100-m*10)

    return seedNumber+j+k+m+n
    
for i in range(10000):
    kaprekarArray[kaprekarFunc(i)] = kaprekarArray[kaprekarFunc(i)] + 1
    
for i in range(10000):
    if kaprekarArray[i] == 0 :  print(i)
