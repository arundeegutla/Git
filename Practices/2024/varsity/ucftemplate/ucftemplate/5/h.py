# take in input
[d, h] = map(int, input().split())

# memoize factorial-related info
factorial = [1]*(h+1)
for i in range(1, h+1):
    factorial[i] = factorial[i-1]*i
numerator = factorial[h-1]
base = set()

# perform all possible combinations of values for each dimension (order doesn't matter)
def multichoose(options, r, high):
    # handle when denominator is full/fixed
    if len(options) == d or high == 0:
        # incomplete
        if r > 0:
            return

        # calculate the multichoose (h-1)!/o1!/o2!/...
        res = numerator
        for k in options:
            res //= factorial[k]
        base.add(res)
        return

    # go through all possible options for the denominator of multichoose
    for i in range(min(high, r) + 1):
        options.append(i)
        multichoose(options, r - i, i)
        options.pop()
multichoose([], h-1, h-1)

# print base in sorted order
for k in sorted(base):
    print(k)

