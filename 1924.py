month, date = map(int, input().split())
days = 0

dateInMonths = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
daysInWeeks = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]

for i in range(0, month - 1):
    days = days + dateInMonths[i]
    
days = days + date

print(daysInWeeks[days%7])
