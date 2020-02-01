sortArray = list(input().split())    #입력함수로 입력받은걸 분리함수로 분리해서 list화 하여 저장

for i in range(len(sortArray)) :    #list인 sortArray의 각 인덱스마다
    sortArray[i] = int(sortArray[i])    #정수로 저장되게끔 해준다

sortArray.sort(reverse=False)    #뒤집지 않고 정렬 (오름차순)
print(sortArray[1])
