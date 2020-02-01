num = int(input())

for i in range(1, num + 1):
    for j in range(num - i, num - 1):
        print(" ", end="")
    for j in range(i, num + 1):
        print("*", end="")
    print()
