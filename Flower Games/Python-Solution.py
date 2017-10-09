T = input()
for t in range(T):
    N = input()
    N -= 2 ** (N.bit_length() - 1)
    N = (N << 1) + 1
    print N