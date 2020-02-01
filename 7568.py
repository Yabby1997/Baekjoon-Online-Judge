numOfCases = int(input())

weight = list()
height = list()
result = list()

for i in range(numOfCases) :
    caseWeight, caseHeight = map(int, input().split())
    weight.append(caseWeight)
    height.append(caseHeight)

for i in range(numOfCases) :
    counter = 1
    for j in range(numOfCases) :
        if weight[j] > weight[i] and height[j] > height[i] :
            counter = counter + 1
    result.append(counter)

for each in result :
    print(each, end=" ")
