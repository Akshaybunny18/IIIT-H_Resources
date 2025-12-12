def pow(x,n):
    if n==0:
        return 1
    if n==1:
        return x
    if n%2==0:
        return pow(x*x,n//2)
    else:
        return x*pow(x*x,(n)//2)
x=int(input("base"))
y=int(input("power"))
print(pow(x,y))