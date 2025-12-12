from loop import loop
from F import F

# ([9 8 12 2], 3) -> ([9 8 2 12], 2) -> ([2 8 9 12], 1) ->  ([2 8 9 12], 0)


# I  = Arr
# A = Arr
# X  = a:Arr, b: [0..len(a)]

# rho: I -> X 
def rho(a):
    return (a, len(a))

# pi: X -> A
def pi(x):
    (a, b) = x
    return a


# selsort: I -> A
def selsort(a): 
    print("------------------")
    print("inst = ", a)
    
    x0 = rho(a)   # initialise
    print("x0=", x0)
    
    fix = loop(F,x0)    # iterate till fix point
    print("fix=", fix)
    
    ans = pi(fix)
    print("ans=", ans)

    return ans

    


