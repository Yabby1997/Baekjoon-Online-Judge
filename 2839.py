sugarAmount = int(input())
output = 0

while True :                              #python에서는 {}대신 :이 쓰인다
    if sugarAmount % 5 == 0 :
        print(output + sugarAmount//5)    #python에서는 자료형구분이 추상적이기때문에 /으로 나누면 소수점아랫자리까지 값이 넘어옴. 몫만 구하고싶다면 //을 사용해야 함
        break
    elif sugarAmount < 0 :                   #python에서는 else if가 아니라 elif로 쓴다
        print(-1)
        break
    sugarAmount = sugarAmount -3
    output += 1                            #python에서는 ++를 사용할 수 없다. 속도에 도움 안되는데? 오히려 이게 빨라.
  
   
