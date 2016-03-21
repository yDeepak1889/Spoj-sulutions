test=int(input())
while(test):
    a=input().split()
    a,b=[int(a[0]),int(a[1])]
    if b==0:
        a=1
    last=a%10
    d=last%5
    if d==0 or d==1:
        incr=1
        loop=1
    elif d==2 or d==3:
        incr=4
        loop=b%incr
        if loop==0:
            loop=4
    elif d==4:
        incr=2
        loop=b%incr
        if loop==0:
            loop=2
    prod=1
    for i in range(loop):
        prod=prod*a
    last=prod%10
    print(last)
    test-=1
