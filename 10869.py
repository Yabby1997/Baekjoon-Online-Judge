a, b = map(int, input().split())
print(a+b)
print(a-b)
print(a*b)
print(int(a/b))       #python은 자료형의 구분이 명확하지 않아서 정수간의 나눗셈도 소숫점을 가질수있음. 따라서 정수값만을 산출하는 //을 사용하거나 int로 형변환해주어야 함.
print(a%b)
