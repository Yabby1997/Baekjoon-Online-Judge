splitedInput = list(map(str, input().split(' ')))
A = int(splitedInput[0][::-1])                          #REVERSE STR WITH [::-1]
B = int(splitedInput[1][::-1])

if A > B:
    print(A)
else:
    print(B)
