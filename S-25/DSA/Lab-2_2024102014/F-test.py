from F import F

assert(F(([3], 1)) == ([3], 0))
assert(F(([3, 2], 2)) == ([2, 3], 1))
assert(F(([2, 3], 1)) == ([2, 3], 0))
assert(F(([2, 3], 0)) == ([2, 3], 0))
