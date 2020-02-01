x = list()
y = list()
X = int()
Y = int()

for i in range(3) :
    a, b = map(int, input().split())
    x.append(a)
    y.append(b)
    
if x[0] == x[1] :
    X = x[2]
elif x[0] == x[2] :
    X = x[1]
elif x[1] == x[2] :
    X = x[0]
    
if y[0] == y[1] :
    Y = y[2]
elif y[0] == y[2] :
    Y = y[1]
elif y[1] == y[2] :
    Y = y[0]
    
print("%d %d" %(X, Y))
