from findmax import findmax
from swap import swap

# F:  X -> X
# X = Arr x Boundary
# x = (a, b)

# (ap, bp) = F(a, b)
def F(x):
    (a, b, c) = x  # pattern matching
    if c == 0:
        return x
    else:
        temp=a
        a=b
        b=a+temp
        return (a,b,c-1)
        # m = findmax(a, b)
        # ap=swap(a, m, b-1)
        # bp = b-1
        # return (ap,bp)
