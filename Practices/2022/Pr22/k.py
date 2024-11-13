line = input()
if '-' in line:
    l = line.split('-')
    if 1 < len(l[0]) <= 8 and 1 <= len(l[1]) <= 24:
        print("YES")
    else:
        print("NO")
else:
    print("NO")