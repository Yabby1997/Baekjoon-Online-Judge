numOfCases = int(input())
nums = list(map(int, input().split()))

maximum = nums[0]
minimum = nums[0]

for each in nums:
    if each > maximum:
        maximum = each
    elif each < minimum:
        minimum = each

print("%d %d"%(minimum, maximum))
