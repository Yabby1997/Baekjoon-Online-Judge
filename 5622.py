inputString = str(input())
sum = 0

for each in inputString:
    if each == 'A' or each == 'B' or each == 'C':
        sum = sum + 3
    elif each == 'D' or each == 'E' or each == 'F':
        sum = sum + 4
    elif each == 'G' or each == 'H' or each == 'I':
        sum = sum + 5
    elif each == 'J' or each == 'K' or each == 'L':
        sum = sum + 6
    elif each == 'M' or each == 'N' or each == 'O':
        sum = sum + 7
    elif each == 'P' or each == 'Q' or each == 'R' or each == 'S':
        sum = sum + 8
    elif each == 'T' or each == 'U' or each == 'V':
        sum = sum + 9
    else:
        sum = sum + 10

print(sum)
