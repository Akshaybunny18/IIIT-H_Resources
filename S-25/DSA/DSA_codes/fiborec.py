def fib(n,a,b):
    if n==1:
        return a
    else:
        return fib(n-1,b,a+b)
x=int(input())
if x==0:
    print(0)
elif x==1:
    print(0)
elif x==2:
    print(1)
else:
    print(fib(x,0,1))