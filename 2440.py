num = int(input())

for i in range(1, num+1):
    for j in range(1, num+2-i):
        print("*", end="")
    print();
    
