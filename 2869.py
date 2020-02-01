import math

up, down, distance = map(int, input().split())
print(int(math.ceil((distance - up)/(up - down))) + 1)
