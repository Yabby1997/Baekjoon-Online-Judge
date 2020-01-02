import math

numOfCases = int(input())

for i in range(numOfCases) :
    height, width, visitors = map(int, input().split())
    hh = visitors % height
    if hh == 0 :
        hh = height
    ww = math.ceil(visitors / height)
    print("%d%02d" %(hh, ww))
