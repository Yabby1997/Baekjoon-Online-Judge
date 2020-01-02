numOfCases = int(input())

for i in range(numOfCases):
    scoreList = list(map(int, input().split()))
    numOfStudents = scoreList[0]                            #first member of scoreList, which means number of students
    del scoreList[0]                                        #delete member of list
    averageScore = float(sum(scoreList)/numOfStudents)
    aboveAverageCounter = 0
    for each in scoreList :
        if each > averageScore:    aboveAverageCounter = aboveAverageCounter + 1
    result = float((aboveAverageCounter*100)/numOfStudents)
    print("%.3f%%" % result)                                #%% prints %   
