def findWays(dice, loc, sumS, target):
    if (loc == len(dice)):
        if (int(sumS) == int(target)):
            return 1
        return 0

    count = 0
    length = dice[loc]
    for i in range(1, length+1):
        count = count + findWays(dice, loc+1, sumS + i, target)

    return count

cases = int(input())

for k in range(cases):
    line = input().split(" ")

    total = int(line[0])

    dice = [0]*total
    possible = 1
    for i in range(1, total+1):
        dice[i-1] = int(line[i])
        possible = possible * dice[i-1]
    
    target = line[len(line) - 1]

    desired = findWays(dice, 0, 0, target)

    ans = round(desired/possible, 9)
    print(f"{k+1}: {ans}")