from __future__ import print_function

NUM_BALLON = 10
NUM_COLOR = 3


class Question:
    def __init__(self, ctype, color, count=None, index=None):
        self.ctype = ctype
        self.color = color
        self.count = count
        self.index = index

    def isTrue(self, colors):
        truth = False
        if self.ctype == 'color':
            truth = colors[self.index] == self.color
        elif self.ctype == 'count':
            count = 0
            for i in range(NUM_BALLON):
                if colors[i] == self.color:
                    count += 1
            truth = count == self.count
        return truth


class Questions:
    def __init__(self):
        self.question_set = []
        self.combine = 1
        self.truth = False

    def isTrue(self, colors):
        result = True
        if self.combine == 1:
            result = True
        elif self.combine == 2:
            result = False
        for i in xrange(len(self.question_set)):
            if self.combine == 1:
                result = result and self.question_set[i].isTrue(colors)
                if result == False: break
            elif self.combine == 2:
                result = result or self.question_set[i].isTrue(colors)
                if result == True: break
        return result

    def satisfy(self, colors):
        return self.isTrue(colors) == self.truth


def number2colors(number):
    colors = []
    for i in range(NUM_BALLON):
        color = number % NUM_COLOR
        number /= NUM_COLOR
        if color == 0:
            colors.append('r')
        elif color == 1:
            colors.append('g')
        elif color == 2:
            colors.append('b')
    return colors


if __name__ == '__main__':
    T = input()
    for t in xrange(T):
        # Read INPUT
        questions = [Questions() for i in range(20)]
        raw_input()
        Q, L = map(int, raw_input().strip().split())
        for q in xrange(Q):
            raw_question = raw_input().strip().split()
            command_index = 0
            while True:
                ctype = raw_question[command_index]
                if ctype == 'color':
                    index = int(raw_question[command_index + 1]) - 1
                    color = raw_question[command_index + 2]
                    question_obj = Question(ctype, color, index=index)
                elif ctype == 'count':
                    color = raw_question[command_index + 1]
                    count = int(raw_question[command_index + 2])
                    question_obj = Question(ctype, color, count=count)

                questions[q].question_set.append(question_obj)

                try:
                    op = raw_question[command_index + 3]
                    if op == 'and':
                        questions[q].combine = 1
                    elif op == 'or':
                        questions[q].combine = 2
                    command_index += 4
                except IndexError:
                    break

            ans = raw_input()
            if ans == 'yes':
                questions[q].truth = True
            elif ans == 'no':
                questions[q].truth = False

        # Iterate all configuration of colors of ballon
        answer = [[False for i in range(NUM_COLOR)] for j in range(NUM_BALLON)]
        for c in xrange(NUM_COLOR ** NUM_BALLON):
            colors = number2colors(c)
            num_lies = 0
            for q in xrange(Q):
                num_lies += questions[q].satisfy(colors) == False
            if num_lies == L:
                for i in range(NUM_BALLON):
                    if colors[i] == 'r':
                        answer[i][0] = True
                    elif colors[i] == 'g':
                        answer[i][1] = True
                    elif colors[i] == 'b':
                        answer[i][2] = True

        # Output
        for i in range(NUM_BALLON):
            if answer[i][0]:    print('r', end='')
            if answer[i][1]:    print('g', end='')
            if answer[i][2]:    print('b', end='')
            if i != NUM_BALLON - 1:    print(' ', end='')
        print('\n', end='')
