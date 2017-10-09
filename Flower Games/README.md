# Xtreme 10.0 - Flower Games

Joy and her friends found a flower with N petals and want to play a modified version of the <a href="https://en.wikipedia.org/wiki/He_loves_me..._he_loves_me_not">He loves me... he loves me not</a> game. The girls number the petals with numbers from 1 to N in the clockwise direction. They will traverse the petals in circular order starting with 1, then 2, ..., then N, then 1... At the first petal, they will shout "He loves me", at the second "He loves me not" and tear it, at the third "He loves me", at the fourth "He loves me not" and tear it. The girls will continue the game until there is only one petal left. The task is to identify the number of the last petal.

### Input Format

The input begins with an integer T, giving the number of test cases in the input.

Each testcase consists of an integer N, on a line by itself.

### Constraints

1 <= T <= 100000

1 <= N < 2^63

### Output Format

The location of the last petal, on a line by itself.

### Sample Input

```
4
2
3
4
6
```

### Sample Output

```
1
3
1
5
```

### Explanation

There are four test cases in the input.

With 2 petals, one would skip 1, tear 2, and then only 1 is left.

With 3 petals, one would skip 1, tear 2, skip 3, tear 1, and then only 3 is left.

With 4 petals, one would skip 1, tear 2, skip 3, tear 4, skip 1, tear 3, and then only 1 is left.

With 6 petals, one would skip 1, tear 2, skip 3, tear 4, skip 5, tear 6, skip 1, tear 3, skip 5, tear 1, and then only 5 is left.

### Analysis

* when the number of petals is 2, the number of the last petal is 1.
* when the number of petals is 3, the number of the last petal is 3.
* when the number of petals is 4, the number of the last petal is 1.
* when the number of petals is 5, the number of the last petal is 3.
* when the number of petals is 6, the number of the last petal is 5.
* when the number of petals is 7, the number of the last petal is 7.
* when the number of petals is 8, the number of the last petal is 1.
* when the number of petals is 9, the number of the last petal is 3.
* when the number of petals is 10, the number of the last petal is 5.

We find that the result is always odd. 

Expressed the integer number as a binary number. 

Remove the lowest bit:

```
0,1,0,1,2,3,0,1,2,3,4,5,6,7
```

Fill the highest bit with <code>1</code>:

```
2,3,4,5,6,7,8,9,10,11,12,13,14,15
```

That's <code>N</code> itself. Reverse this process we can easily obtain the result in <code>O(1)</code>.