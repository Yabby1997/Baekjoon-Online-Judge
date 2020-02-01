while True :
    x, y, z = map(int, input().split())
    if x == 0 and y == 0 and z == 0 :
        break
    else :
        if x * x + y * y == z * z or x * x + z * z == y * y or y * y + z * z == x * x :
            print("right")
        else :
            print("wrong")
        
