def rs(num):
    return (num* (num+1))//2

def pot(n, lower, upper, target):

    while lower <= upper:
        ans = (lower+upper)// 2

        total = rs(ans) - rs(n-1)

        if total == target:
            return f"{target} = {n} to {ans}"
        elif total > target:
            upper = ans-1
        else:
            lower = ans+1
    

while True:
    num = int(input())
    half = num//2
    need = 0

    if num == 0:
        break

    
    for i in range(3, num+1, 2):
        if num % i == 0:
            need += 1

    if need == 0:
        print(f"{num} is not polite")
    else:
        for n in range(1, half+1):
            upper = half + 1
            lower = n+1

            ans = pot(n, lower, upper, num)
            
            if ans:
                print(ans)
                need -= 1

            if need == 0:
                break
            

    
    # if need > 0:
    #     print(f"{num} is not polite")