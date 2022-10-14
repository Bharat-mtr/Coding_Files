n= int(input("Enter the number to check for Prime Number: "))
k=int ((n**0.5)//1)
if(n>1):
    for i in range(2,k):
        if(n%k==0.0):
            print("Number is not Prime")
            break 
    else:
        print("Number is prime")
else:
    print("Number is not prime")
    
