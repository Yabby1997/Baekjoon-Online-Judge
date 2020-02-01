guys = [0]*5
scores = [0]*5

for i in range(5):
    guys[i] = int(input())
    
for i in range(len(guys)):
    if guys[i] < 40:
        scores[i] = 40
    else:
        scores[i] = guys[i]
    
print(int(sum(scores)/5))
