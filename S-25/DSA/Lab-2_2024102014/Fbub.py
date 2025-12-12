from Fbubi import Fi
from loop import loop
# F:  X -> X
# X = Arr x Boundary
# x = (a, b)


def F(x):
    (a, b) = x  # pattern matching
    if a == [] :
        return ([],b)
    if b == len(a)-1 :
        return x
    else:
        # temp=a
        # a=b
        # b=a+temp
        # return (a,b,c-1)
        ffix=loop(Fi,(a,0,b))
        print("ffix=", ffix)
        return (a,b+1)
        # for i in range(0,len(a)-b-1) :
        #     if (a[i]>a[i+1]) : 
        #         swap(a,i,i+1)
        # return (a,b+1)
