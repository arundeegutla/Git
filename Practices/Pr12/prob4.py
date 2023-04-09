for t in range(int(input())):
    t, b = map(int, input().split("/"))
    r = None
    
    while True:
        wn = t//b
        r = t % b

        t, b = b, r

        if r == 0:
            print(wn)
            break
        else:
            print(f"{wn}, ", end = "")