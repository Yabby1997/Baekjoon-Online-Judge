cellNumber = int(input())

cellAmount = 1;
level = 0;

if cellNumber == 1:
    level = 1
    
while cellAmount < cellNumber:
    cellAmount = cellAmount + 6 * level
    level = level + 1
    
print(level)
