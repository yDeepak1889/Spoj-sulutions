n=int(input())
sum=n
for i in range(2,int(n/2)+1):
    j=2
    while(i*j<=n and j<=i):
        sum=sum+1
        j+=1
print(sum)
 
