def factorial(inputNum):
    result = 1
    for i in range(inputNum):
        result = result * (inputNum - i)
    return result

print(factorial(int(input())))
