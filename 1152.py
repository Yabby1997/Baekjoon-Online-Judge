inputString = input()

wordCounter = 1

for each in inputString:
    if each == ' ': wordCounter = wordCounter + 1
if inputString[0] == ' ':    wordCounter = wordCounter - 1
if inputString[len(inputString)-1] == ' ':    wordCounter = wordCounter - 1     #len func returns length of list
    
print(wordCounter)
