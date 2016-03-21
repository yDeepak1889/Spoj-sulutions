test=int(input())
while(test):
    n=int(input())
    arr1=[]
    num=input().split()
    for i in range(n):
        arr1.append(int(num[i]))
    arr2=[]
    num=input().split()
    for i in range(n):
        arr2.append(int(num[i]))
    arr1.sort()
    arr2.sort()
    sum=0
    for i in range(n):
        sum=sum+arr1[i]*arr2[i]
    print(sum)
    test-=1
