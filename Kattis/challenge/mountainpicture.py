n = int(input())
mountains = list(map(int, input().split()))
everestx = -1
everesty = -1
for i in range(n):
    if(mountains[i] > everesty):
        everestx = i
        everesty = mountains[i]

h = mountains[0]
lo = 0
hi = 1e8
ans = -1
while(lo <= hi):
    mid = (lo+hi)//2
    x = -mid
    y = h+4
    m = (everesty-y)/(everestx-x)
    b = y - (m*x)

    works = True
    for i in range(everestx):
        if(((m*i)+b) <= mountains[i]):
            works = False
    
    if (works):
        hi = mid - 1
        ans = mid
    else:
        lo = mid + 1

print(int(ans));
