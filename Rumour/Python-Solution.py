import math

q = input()
for _ in range(q):
    a, b = tuple(map(int, raw_input().split()))
    if a == b:
        print 0
        continue
    ax = int(math.ceil(math.log(a + 1, 2)))
    bx = int(math.ceil(math.log(b + 1, 2)))
    d = 0
    if ax > bx:
        for _i in range(ax - bx):
            a //= 2
            d += 1
            ax -= 1
    if ax < bx:
        for _i in range(bx - ax):
            b //= 2
            d += 1
            bx -= 1
    # print ax,bx
    while a != b:
        a //= 2
        b //= 2
        d += 2
    print d
