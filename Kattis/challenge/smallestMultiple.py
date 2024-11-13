import math
while 1:
    try: 
        nums = list(map(int, input().split()))
        lcm = 1
        for x in nums:
            lcm = (lcm * x) // math.gcd(lcm, x)
        print(lcm)
    except: 
        break
