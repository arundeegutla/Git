def solve():
    cat = [0] * 5001
    cat[0] = 1
    for i in range(1, 5001):
        cat[i] = cat[i-1]
        cat[i] *= (4*i-2)
        cat[i] //= (i+1)
    n = nextInt()
    while n > 0:
        print(cat[nextInt()])
        n -= 1

def nextInt():
    return int(input())

def nextLong():
    return int(input())

def next():
    return input()

solve()
