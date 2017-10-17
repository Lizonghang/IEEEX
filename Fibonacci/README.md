# Fibonacci

Dr. Fibonacci is modeling the bacteria population growth using a famous sequence. Initially, a bacterium is placed inside a test tube. There will be 1 bacterium in the first minute, 2 bacteria in the second minute, 3 in the third minute, 5 in the fourth minute and so on. At the end of the minute n, the number of bacteria will be equal to the number of bacteria in minute n−2 plus the number of bacteria in minute n−1.

Dr. Xtreme wants Dr. Fibonacci to use the same model with an enhancement to model the human population growth. Dr. Xtreme wants to enhance the model by including a disaster scenario where most humans are destroyed. If there is a disaster in generation m, then only the number of humans in that generation modulo 10 will survive. You goal is develop the model with the disaster scenario, so that we can compute how many humans will survive after the disaster occurs. ### Standard input

Input begins with a single number t(1≤t≤100), which denotes the number of test cases.On the following t lines there will be a single integer m(1≤m≤10^9) which indicates the generation where the disaster occurs for the specific test case.Please note that there will be only one disaster per test case.### Standard output

For each test case, output a single integer per line indicating the number of humans who survived the disaster.### Constraints and notes* 1≤t≤100 * 1≤m≤10^9
* Time limit: 200 ms
* Memory limit: 256 MB

### Input & Output

input:

```
3
2
4
10
```

output:

```
2
5
9
```

### Explanation

There are three test cases. At the end of 2nd, 4th and 10th generation, there will be 2, 5 and 89 humans respectively. When the disaster occurs, there will be 2, 5 and 9 humans left.