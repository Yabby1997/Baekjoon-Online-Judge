A = int(input())
B = int(input())
C = int(input())

ABClist = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
ABC = str(A*B*C)

for each in ABC:
    if each == '0': ABClist[0] = ABClist[0] + 1
    elif each == '1':  ABClist[1] = ABClist[1] + 1
    elif each == '2':  ABClist[2] = ABClist[2] + 1
    elif each == '3':  ABClist[3] = ABClist[3] + 1
    elif each == '4':  ABClist[4] = ABClist[4] + 1
    elif each == '5':  ABClist[5] = ABClist[5] + 1
    elif each == '6':  ABClist[6] = ABClist[6] + 1
    elif each == '7':  ABClist[7] = ABClist[7] + 1
    elif each == '8':  ABClist[8] = ABClist[8] + 1
    else:  ABClist[9] = ABClist[9] + 1

for each in ABClist:
    print(each)
