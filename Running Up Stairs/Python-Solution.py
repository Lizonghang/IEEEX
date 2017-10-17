T = input()
for t in range(T):
    n = input()
    i = 1
    j = 1
    x = 1
    while x < n:
        tmp = i + j
        i = j
        j = tmp
        x += 1
    print j
