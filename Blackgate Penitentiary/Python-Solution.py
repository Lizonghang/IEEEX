from __future__ import print_function

N = input()
d = {}
for n in range(N):
    name, h = raw_input().strip().split()
    h = int(h)
    if d.has_key(h):
        d[h].append(name)
    else:
        d[h] = [name]
count_min = 1
count_max = 1
for h in sorted(d.keys()):
    names = sorted(d[h])
    count_max += len(names) - 1
    for name in names:
        print(name, end=" ")
    print(count_min, end=" ")
    print(count_max)
    count_min = count_max + 1
    count_max = count_min
