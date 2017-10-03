import numpy as np

NUM_COLOR = 20
MAX_CHANGE = np.inf

if __name__ == '__main__':
    T = input()
    for t in range(T):
        max_time = input()
        colors = map(lambda c: int(c) - 1, raw_input().strip().split())

        count = np.ones((max_time + 1, NUM_COLOR + 1, NUM_COLOR + 1), dtype=np.int32) * np.inf
        count[0][NUM_COLOR][NUM_COLOR] = 0

        for t in range(1, max_time + 1):
            for c1 in range(NUM_COLOR + 1):
                for c2 in range(NUM_COLOR + 1):
                    if c1 == colors[t - 1] or c2 == colors[t - 1]:
                        count[t][c1][c2] = min(MAX_CHANGE,
                                               count[t - 1, c1, :].min() + 1,
                                               count[t - 1, :, c2].min() + 1,
                                               count[t - 1, c1, c2])
                    else:
                        count[t][c1][c2] = MAX_CHANGE

        print int(min(MAX_CHANGE,
                      count[max_time, :, colors[-1]].min(),
                      count[max_time, colors[-1], :].min()))