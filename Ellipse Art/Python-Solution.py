"""
Score: 0.00
Status: Terminated due to timeout
Use C++ instead
"""

T = input()
d = 0.1
for t in range(T):
    N = input()
    ellipses = []
    counter = 0
    for n in range(N):
        ellipses.append(map(int, raw_input().strip().split()))
    grid = [[x, y]
            for x in [d * i - 50 for i in range(int(100 / d) + 1)]
            for y in [d * j - 50 for j in range(int(100 / d) + 1)]]
    for x, y in grid:
        in_ellipse = False
        for ellipse in ellipses:
            if ((x - ellipse[0]) ** 2 + (y - ellipse[1]) ** 2) ** 0.5 + \
               ((x - ellipse[2]) ** 2 + (y - ellipse[3]) ** 2) ** 0.5 \
               < ellipse[4]:
                in_ellipse = True
                break
        if in_ellipse:  counter += 1
    print '{}%'.format(int(round((1 - float(counter) / len(grid)) * 100, 1)))