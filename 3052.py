remainderArray = []
counter = 0
for i in range(42):
    remainderArray.append(0)
for i in range(10):
    tempIn = int(input())
    remainderArray[tempIn%42] = remainderArray[tempIn%42]+1
for i in range(42):
    if remainderArray[i] != 0:
        counter = counter + 1
print(counter)

    
