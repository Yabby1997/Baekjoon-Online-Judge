length = int(input())
num = list(input())            #배열 list
output = 0

for element in num:                  #인덱스로 명시할것도 없이 그냥 num리스트의 i들에대해서 라고 하면 됨
    output = output + int(element)
    
print(output)
