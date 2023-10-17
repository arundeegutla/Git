import math

def go(index):
    row = math.ceil(math.sqrt(index));
    p = row - 1;
    col = index - (p*p);
    numInRow = row + (row-1);

    sum = (p*(p+1))*(2*p+1) // 6;
    if(col <= row):
        sum += (col*(col+1)) // 2;
    else:
        sum += (row*(row+1)) // 2;
        sum += ((row-1)*((row-1)+1)) // 2;
        sub = numInRow-col;
        sum -= (sub*(sub+1)) // 2;
    return sum

def solve(n):
    lo = 1;
    hi = int(1e13);
    ans = -1;
    while(lo <= hi):
        mid = (lo+hi)//2;
        count = go(mid)
        if(count >= n):
            hi = mid - 1
            ans = mid
        else:
            lo = mid + 1
    return ans

with open('army.in') as f:
    t = int(f.readline())
    for i in range(1, t+1):
        print(f"Case {i}: {solve(int(f.readline()))}")