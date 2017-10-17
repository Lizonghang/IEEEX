# BeetleBag

Beetleman joined the Strangers, a team of super heroes who protect cyber world. 

In order to increase Beetleman's fighting power, Copperman allowed Beetleman to choose gadgets from his labs freely.

However, Beetleman has limited space in his hero bag.

Your task is to help Beetleman choose gadgets to increase his fighting power as much as possible.### Standard input
The first line of input has one integer t(1≤t≤25), the number of test cases that will follow.For each t there will be a line that contains two integers, c (1≤c≤500), the capacity of Beetleman's bag, and number n (1≤n≤200), the number of gadgets in Copperman labs.Then for each above line, there will be n lines that will contain two integers, the number w (1≤w≤100), the gadget's weight and the number f (1≤f≤1000), the fighting power of the gadget.### Standard output
Output will have t lines containing the maximum fighting power from Copperman's gadgets that can fit into Beetleman's bag.### Constraints and notes* 1≤t≤25
* 1≤c≤500
* 1≤n≤20
* 1≤w≤100 for 1≤i≤n
* 1≤f≤1000 for 1≤i≤n

### Input & Output

input:

```
2
6 2
1 17
6 15
5 5
1 1
2 2
3 3
4 4
5 5
```

output:

```
17
5
```

### Explanation

Input explanation:

```
2    <<<< two test cases
6 2  <<<< the first test case has 6 capacity and 2 gadgets to choose from.
1 17 <<<< weight 1, fighting power 17
6 15 <<<< weight 6, fighting power 15
5 5  <<<< the second test case has 5 capacity and 5 gadgets to choose from.
1 1  <<<< weight 1, fighting power 1
2 2  <<<< weight 2, fighting power 2
3 3  <<<< weight 3, fighting power 3
4 4  <<<< weight 4, fighting power 4
5 5  <<<< weight 5, fighting power 5
```

Output explanation```
17 <<<< maximum fighting power from first test case
5  <<<< maximum fighting power from second test case
```