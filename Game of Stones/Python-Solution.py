"""
Score: 90.00
Status: Terminated due to timeout (>10s)
Test Case: #4
"""

T = input()
for t in range(T):
    winner = 0
    G = input()
    for g in range(G):
        input()
        # method sum
        for odd in map(lambda c: (int(c) >> 1) & 1, raw_input().strip().split()):
            winner ^= odd
    """
        # method bitsum
        piles_strip_times = map(lambda c: int(c) / 2, raw_input().strip().split())
        winner += sum(piles_strip_times)
    winner &= 1
    """
    if winner == 1:
        print 'Alice'
    else:
        print 'Bob'
