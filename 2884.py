inHour, inMinute = map(int, input().split())
outHour = 0
outMinute = 0
if inMinute < 45 :
    outMinute = 15 + inMinute
    outHour = inHour - 1
else :
    outMinute = inMinute - 45
    outHour = inHour
if outHour < 0 :
    outHour = 24 + outHour
print(outHour,outMinute)                #AUTOMATICALLY INSERT SPACE BETWEEN VARIABLES WHEN USING , BETWEEN
