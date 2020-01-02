numOfInput = int(input())
scoreArray = list(map(float, input().split()))            #list에 map해준다 float형으로 input값을 split해서
result = float(((sum(scoreArray)*100)/(numOfInput*max(scoreArray))))

print('%.2f' %result)    #계산된 result값을 소숫점 2째자리까지 포맷팅해서 출력
