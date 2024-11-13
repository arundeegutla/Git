# get prime factors
# total divisors for each product of sums(power + 1)
import math


n = int(input())
d = {}

while (n%2 == 0):
    if 2 in d:
        d[2] += 1
    else:
        d[2] = 1
    n = n//2

for i in range(3, int(math.sqrt(n))+1, 2):
    while (n % i == 0):
        if i in d:
            d[i] += 1
        else:
            d[i] = 1

        n = n//i

if (n > 2):
    d[n] = 1

# print(d)

count = 1
for i in d:
    count = (count) * (d[i] + 1)
print(count)
