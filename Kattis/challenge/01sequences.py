MOD = int(1e9) + 7

s = input()
tot = 0
oneCount = 0
choose = 0
for i in range():
    if(c=='1'):
        oneCount+=1
    else:
        # oneCount ..... onec+choose
        x = oneCount+choose
        tot += (x*(x+1))//2
        tot -= ((oneCount-1)*(oneCount))//2
        tot %= MOD
        if(c=='?'):
            choose+=1
    print(oneCount, choose, tot)
    
print(tot)

    
    

