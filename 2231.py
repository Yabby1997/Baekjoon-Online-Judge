inputNum = int(input())
result = 0

for i in range(inputNum) :
    a = int(i / 1000000)
    b = int((i - a * 1000000) / 100000)
    c = int((i - a * 1000000 - b * 100000) / 10000)
    d = int((i - a * 1000000 - b * 100000 - c * 10000) / 1000)
    e = int((i - a * 1000000 - b * 100000 - c * 10000 - d * 1000) / 100)
    f = int((i - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100) / 10)
    g = int(i - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10)
    if (i + a + b + c + d + e + f + g) == inputNum :
        result = i;
        break;
    
print(result)
