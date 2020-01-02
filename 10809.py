inputString = str(input())
indexOfAlphabet = [-1]*26
alphabetList = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

for i in range(26):
    print("%d " % (inputString.find(alphabetList[i])), end='')                  #FIND RETURNS INDEX OF SPECIFIC CHAR
