# Xtreme 10.0 - Counting Molecules

Your task is to count the number of molecules in a cup of soda which contains distilled water, carbon dioxide, and glucose. You have a machine that counts the number of atoms of carbon, hydrogen, and oxygen in a given sample.

### Input Format

The input consists of a single line with three space separated integers: <code>c</code>, <code>h</code>, and <code>o</code>, where:

* <code>c</code> is the count of carbon atoms.
* <code>h</code> is the count of hydrogen atoms.
* <code>o</code> is the count of oxygen atoms.

### Constraints

0 ≤ <code>c</code>, <code>h</code>, <code>o</code> < 10^10

### Output Format

If the number of atoms is consistent with a mixture containing only water, carbon dioxide, and glucose molecules, the output should consist of a single line containing three space separated integers: the number of water molecules, the number of carbon dioxide molecules, and the number of glucose molecules.

If the number of atoms is not consistent with a mixture containing only water, carbon dioxide, and glucose molecules, the output should consist of a line containing the word <code>Error</code>.

### Sample Input

```
10 0 20
```

### Sample Output

```
0 10 0
```

### Explanation

The input indicates that there are 10 carbon atoms and 20 oxygen atoms. The only way that this could occur would be if there were 0 water molecules, 10 carbon dioxide molecules, and 0 glucose molecules.

### Analysis

```
A = [[ 0,  1,  6],
     [ 2,  0, 12],
     [ 1,  2,  6]]

B = [[H2O_c],
     [CO2_c],
     [C6H12O6]]

C = [[c],
     [h],
     [o]]
```

```
A * B = C --> B = A.I * C

[[H2O_c],          [[-1 ,  1/4 ,   1/2],        [[c],
 [CO2_c],     =     [0  , -1/4 ,   1/2],   *     [h],
 [C6H12O6]]         [1/6,  1/24, -1/12]]         [o]]
```

To ensure <code>H20,CO2,C6H12O6</code> are integers:

```
[[H2O_c],          [[-4 , 1 , 2],        [[c],
 [CO2_c],     =     [ 0 ,-1 , 2],   *     [h],
 [C6H12O6]]         [ 4 , 1 ,-2]]         [o]]
```

and finally output <code>H2O\_c/4</code>, <code>CO2\_c/4</code>, <code>C6H12O6\_c/24</code> or <code>Error</code> if negative value occurs.