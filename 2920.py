melodyList = list(map(int, input().split()))
melodyCheck = [0]*7
output = 0

for i in range(len(melodyList)-1):                          #LEN FUNCTION RETURNS LENGTH OF LIST
    melodyCheck[i] = melodyList[i+1]-melodyList[i]

for i in range(len(melodyCheck)-1):
    if melodyCheck[i] == melodyCheck[i+1]:
        output = melodyCheck[i]
    else:
        output = 0
        break                                               #YOU CAN USE BREAK IN PYTHON

if output == 1:
    print("ascending")
elif output == -1:
    print("descending")
else:
    print("mixed")
