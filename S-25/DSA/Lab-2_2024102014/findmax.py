from loop import loop

# find the position of the max
# element in the subarray a[0..b)

# I = a: Arr, b:[0..len(a)],  len(a)>1
# A = [0..len(a)-1]
# X = (a: Arr, b: [0..len(a)], i: [0..b], m: [0..i])

# rho: I -> X
def rho(a, b):
    return (a, b, 0, 0)

# F: X -> X
def F(x):
    (a, b, i, m) = x
    if i == b:
        return x
    elif a[m] < a[i]:
        return (a, b, i+1, i)
    else:
        return (a, b, i+1, m)

# pi: X -> A
def pi(x):
    (a, b, i, m) = x
    return m

# findmax: I -> A
def findmax(a,b):
    x0 = rho(a, b)
    fix = loop(F, x0)
    ans = pi(fix)
    return ans

# def findmax(a, b):
#     i = 0
#     m = 0
#     while (i < b):
#         if a[m] < a[i]:
#             m = i
#         i = i+1
#     return m

