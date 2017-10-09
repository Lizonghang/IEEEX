b, symbols = raw_input().strip().split()
b = int(b)
number1 = raw_input()[1:]
number2 = raw_input()[1:]
sp = raw_input()
raw_input()

C = 0
result = ''
d = {' ': 0}
for i, c in enumerate(symbols):
    d[c] = i

for i in reversed(range(len(number1))):
    total = d[number1[i]] + d[number2[i]] + C
    C = total / b
    # Timeout
    # result = symbols[total % b] + result
    result += symbols[total % b]

print b, symbols
print '', number1
print '+{}'.format(number2)
print sp
print '', result[::-1]
