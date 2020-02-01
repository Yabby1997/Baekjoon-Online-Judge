inputString = str(input())        #string은 str이다. cast도 str()
index = 0

for eachChar in inputString:    #파이썬은 진짜 다양한방식으로 쓰이는듯. 오히려 더 어렵다..
    print(eachChar, end="")
    index = index + 1          
    if index % 10 == 0:
        print()
