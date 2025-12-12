from loop import loop

# 
# x: Nat
# H: Nat -> Nat
# H decrements x if it is non-zero.
def H(x):
    print("x=", x)
    if (x == 0):
        return x
    else:
        return x-1

assert(loop(H, 0) == 0)
assert(loop(H, 2) == 0)
assert(loop(H, 4) == 0)


# X = Nat x Nat
# x = (i: Nat, a: Nat)
# G: X -> X
def G(x):
    (i, a) = x
    if (i == 0):
        return x
    else:
        return (i-1, a*i)

assert(loop(G, (2, 3)) == (0, 6))
assert(loop(G, (2, 1)) == (0, 2))
assert(loop(G, (4, 1)) == (0, 24))


# Collatz conjecture:   Every sequence starting with a positive
# number will reach 1.
# X = Nat
# F: X -> X
# F is based on the Collatz operation
def F(x):
    if x == 1:
        return x
    else:
        if (x % 2 == 0):
            return x // 2
        else:
            return 3*x + 1

assert(loop(F, 5) == 1)
assert(loop(F, 237) == 1)
assert(loop(F, 0) == 0)


