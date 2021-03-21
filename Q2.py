s = input("請輸入運算式: (輸入 @ 結束)")
while(s!="@"):
    print("你輸入的數學運算式為: ")
    print(s)
    ans = eval(s)%10000
    print("運算結果"+str(ans))
    s = input("請輸入運算式: (輸入 @ 結束)")
