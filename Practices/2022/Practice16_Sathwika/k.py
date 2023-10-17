def checkPrime(num):
    if (num <= 1):
        return False

    d = 2
    while (d * d <= num):
        if num % d == 0:
            return False
        d += 1
    return True

line = input()
n = int(line)

if not checkPrime(n):
    print("no")
    exit(0)

upsideDown = ""
for i in line[::-1]:
    if i == '6':
        upsideDown = upsideDown + '9'
    elif i == '9':
        upsideDown = upsideDown + '6'
    elif i == '3' or i == '4' or i == '7':
        print("no")
        exit(0)
    else:
        upsideDown = upsideDown + i

# print(upsideDown)
uD = int(upsideDown)
if (checkPrime(uD)):
    print("yes")
else:
    print("no")