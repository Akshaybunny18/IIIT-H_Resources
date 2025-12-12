from Fbub import F
from loop import loop

def rho(a):
    return (a, 0)

# pi: X -> A
def pi(x):
    (a, b) = x
    return a

def bubsort(a) :
    
    x0=rho(a)
    print("x0=", x0)
    
    fix = loop(F,x0)    # iterate till fix point
    print("fix=", fix)
    
    ans = pi(fix)
    print("ans=", ans)
    
    return ans
