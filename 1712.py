infraCost, productionCost, productPrice = map(int, input().split())

if productPrice - productionCost <= 0 :
    print(-1)
else :
    print(int(infraCost/(productPrice - productionCost) + 1))


