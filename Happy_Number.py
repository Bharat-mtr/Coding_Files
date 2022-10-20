n=int(input("Enter The NUMBER:"))
while(n>0 and not n==1):
    k=n
    n=0
    while(k>0):
        p=k%10
        n=n+(p**2)
        k=k//10
        print(n,k)
        
if(n==1):print("HAPPY NUMBER")
else:print("UNHAPPY NUMBER")