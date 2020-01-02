numOfCases = int(input())
nonGroupedWords = 0
alphabetString = "abcdefghijklmnopqrstuvwxyz"

for i in range(numOfCases):
    nonGroupedChars = 0
    recentlyAppeared = [-99]*26
    inputString = str(input())
    
    for index in range(len(inputString)):
        for alphabet in alphabetString:
            if inputString[index] == alphabet:
                if recentlyAppeared[alphabetString.find(alphabet)] == index-1 or recentlyAppeared[alphabetString.find(alphabet)] == -99:
                    recentlyAppeared[alphabetString.find(alphabet)] = index
                else:
                    nonGroupedChars = nonGroupedChars + 1
    
    if nonGroupedChars > 0:
        nonGroupedWords = nonGroupedWords + 1

print(numOfCases - nonGroupedWords)
    
