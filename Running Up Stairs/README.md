# Running Up Stairs

Every 12-year-old boy (at least in America) feels the need to run up the stairs skipping some of them. For this problem, we are going to assume that he randomly skips single steps. (with each step of his foot, he may land on the next step or he may skip one step and land on the following step). For example, if there are three steps, he could traverse them three ways:![](fig1.png)

The challenge in this problem is: given a number of stairs, calculate the number of ways he could traverse them.

### Standard input

The input will start with a single line containing one integer t(1≤t≤5) specifying the number of instances of the problem. Each subsequent line will contain one instance of the problem – a single integer n(1≤n≤22000)  specifying the number of steps in the stair case.### Standard output

For each instance of the problem, your program must output one line containing a single integer – the number of ways the steps could be traversed.### Constraints and notes* 1≤t≤5 * 1≤n≤22000 * Time limit: 2500 ms
* Memory limit: 128 MB

### Input & Output

input:

```
1
3
```

output:

```
3
```

input:

```
1
5
```

output:

```
8
```

input:

```
2
1
2
```

output:

```
1
2
```