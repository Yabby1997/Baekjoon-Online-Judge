score = input()
score = int(score)

if score < 0 or score > 100 :
    print("점수는 0에서 100 사이가 입력되어야 합니다.")
else :
    if score >= 90 : print("A")
    elif score >= 80 : print("B")
    elif score >= 70 : print("C")
    elif score >= 60 : print("D")
    else : print("F")
