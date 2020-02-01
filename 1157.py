inputString = str(input()).upper()                                                                  #TAKE INPUT AS STRING WITH UPPERCASE CHARACTERS
alphabetCounter = [0]*27
alphabetString = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ?'
mostAppearedIndex = 0

for each in inputString:
    alphabetCounter[alphabetString.find(each)] = alphabetCounter[alphabetString.find(each)] + 1     #FIND FUNC RETURNS INDEX OF SPECIFIC CHAR IN STR

for i in range(26):
    if alphabetCounter[i] > alphabetCounter[mostAppearedIndex]:
        mostAppearedIndex = i
        
for i in range(26):
    if i != mostAppearedIndex and alphabetCounter[i] == alphabetCounter[mostAppearedIndex]:
        mostAppearedIndex = 26
    
print(alphabetString[mostAppearedIndex])
