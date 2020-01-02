numOfCase = int(input())

def calcScore(givenCase):
    scoreList = [0]*80
    sizeOfCase = len(givenCase)
    if(givenCase[0] == 'O'):
        scoreList[0] = 1
    for i in range(sizeOfCase):
        if i != 0 and givenCase[i] == 'O':  
            scoreList[i] = scoreList[i-1] + 1
    return sum(scoreList)
    
for i in range(numOfCase):
    inputCase = input()
    print(calcScore(inputCase))
