import math
t = int(input())
while(t):
    found = False
    n = int(input())
    for power in range(2, 30):
        lo = 2
        hi = 1000
        while(lo <= hi):
            mid = (lo+hi)//2
            ans = (1-(mid**(power+1)))/(1-mid)
            if(ans > n):
                hi = mid - 1
            elif(ans < n):
                lo = mid + 1
            else:
                found = True
                print("YES")
                break
        if(found):
            break

    if(not found): 
        print("NO")
    t-=1        
    