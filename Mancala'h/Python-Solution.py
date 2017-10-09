"""
Score: 93.10
Test Case Error: #12, #17
"""


def find_depth(s):
    index = -1
    states = []
    while True:
        states.append(s[:])
        front = s.pop(0)
        q_size = len(s)
        for i in range(min(front, q_size)):
            s[i] += 1
        if front > q_size:
            for i in range(front - q_size):
                s.append(1)
        try:
            index = states.index(s)
            break
        except ValueError:
            pass
    return index


def find_height(state, state_cache):
    max_depth = 0
    for l in reversed(range(len(state))):
        s = state[:]
        for i in range(l + 1):
            s[i] -= 1
        invalid_state = False
        for i in range(len(s) - 1):
            if s[i] == 0 and s[i + 1] != 0:
                invalid_state = True
                break
        if not invalid_state:
            s.insert(0, l + 1)
            while s[-1] == 0:  s.pop(-1)
            try:
                state_cache.index(s)
                break
            except ValueError:
                pass
            state_cache.append(s[:])
            max_depth = max(max_depth, find_height(s, state_cache) + 1)
            state_cache.pop(-1)
    return max_depth


if __name__ == '__main__':
    state = map(int, raw_input().strip().split())
    state_cache = state[:]
    print '{} {}'.format(find_depth(state[:]), find_height(state, state_cache))
