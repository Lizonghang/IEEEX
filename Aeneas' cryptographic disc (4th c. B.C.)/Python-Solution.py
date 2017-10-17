import math

R = input()
d = {}
for i in range(26):
    c, angle = raw_input().split()
    angle = float(angle)
    d[c] = angle
string = raw_input().upper()
new_string = ''
for i in xrange(len(string)):
    if string[i].isalpha():
        new_string += string[i]
string = new_string
del new_string


def get_d(a2, a1):
    return 2 * R * math.sin(abs(a2 - a1) / 2.0)


total_d = 0
for i in xrange(len(string) - 1):
    char1 = string[i]
    char2 = string[i + 1]
    a1 = math.pi * d[char1] / 180.0
    a2 = math.pi * d[char2] / 180.0
    total_d += get_d(a2, a1)
print int(math.ceil(total_d + R))
