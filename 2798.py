numOfCards, maxSum = map(int, input().split())
cards = list(map(int, input().split()))
bestRecord = 0

for i in range(0, numOfCards) :
    for j in range(i + 1, numOfCards) :
        for k in range(j + 1, numOfCards):
            sumOfCards = cards[k] + cards[j] + cards[i]
            if sumOfCards == maxSum :
                bestRecord = sumOfCards
                break;
            elif sumOfCards > bestRecord and sumOfCards < maxSum :
                bestRecord = sumOfCards
                
print(bestRecord)
