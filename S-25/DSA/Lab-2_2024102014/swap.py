# assumes 0 < i, j < len(a)
def swap(a, i, j):
    (a[i], a[j]) = (a[j], a[i])
    return a
