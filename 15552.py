import sys            #sys.stdin.readline()을 사용하기위해 sys를 import해준다.

iteration = int(sys.stdin.readline())    #반복횟수 iteration을 s.s.r로 입력받는다.
for i in range(iteration):                #i가 iteration보다 작을때 반복
    a,b = map(int, sys.stdin.readline().split())    #s.s.r로 문자열을 받아 나누어 정수로 a와 b에 저장
    print(a+b)              
    
