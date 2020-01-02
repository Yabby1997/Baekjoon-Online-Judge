inputString = str(input())
croatianAlphabet = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]

for each in croatianAlphabet:
    inputString = inputString.replace(each, "@")

print(len(inputString))


