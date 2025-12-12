# max2 takes two numbers and returns the maximum of the two.
# if the two are equal, it return any one of them.
def max2(x,y):
    if x > y:
        return x
    else:
        return y

x=3
y=4
a = max2(x,y)
print("x=", x, " y=", y)
print("a=", a)
