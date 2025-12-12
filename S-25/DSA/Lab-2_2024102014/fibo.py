from loop import loop
from F import F

# rho: I -> X 
def rho(a):
    return (0,1,a-2)

def pi(x):
    (a, b, c) = x
    return b


def fibo(a):
    x0 = rho(a)   # initialise
    print("x0=", x0)
    
    fix = loop(F,x0)    # iterate till fix point
    print("fix=", fix)

    ans=pi(fix)
    print("ans=", ans)



    return ans