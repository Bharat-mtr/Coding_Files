n=int(input("Enter the number for its Factorial: "))
if(n>=0):
    if(n==0):
        print("1")
    else:
        s=1
        for i in range(1,n):
            s=s*i
    
        print(s)
