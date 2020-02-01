def alphaCentauri(distance) : 
    i = 1
    result = 0
    while(True) :
        distance = distance - i
        if(distance <= 0) :
            result = 2 * i - 1
            break
        distance = distance - i
        if(distance <= 0) :
            result = 2 * i
            break
        i = i + 1
    return result

numOfInput = int(input())

for i in range(numOfInput) :
    departure, destination = map(int, input().split())
    distance = destination - departure;
    print(alphaCentauri(distance))
    
