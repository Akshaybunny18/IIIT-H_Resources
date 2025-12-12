def loop(F,x):
    while (x != F(x)):
        x = F(x)
    return x
# ----------------------------
def loop(F,x):
    print()
    while True: 
        print("x=", x)
        xp = F(x) # x' = F(x)
        if (x == xp): # fixed point
            return x  # done, return
        else:
            x = xp    # update x to F(x)


        
