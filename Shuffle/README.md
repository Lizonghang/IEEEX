# Shuffle

A group of scientists wish to start an experiment in a village. It consists of swapping lodging of families for a week and then collecting data through a survey.

For the experiment to be a success, there are certain rules that should be followed, namely:

* No family should be sent to its own lodging,
* No family should be sent to a lodging it has already visited.Under these conditions, the scientists would like to know if such a shuffle of lodgings is possible. If not, they are ready to send some families to a hotel and would like to know what is the minimum number of families that should be sent to the hotel in order to make the experiment become possible (note that when a family is sent to the hotel, its lodging can still be used for another family). ### Standard input

The first line of the input contains the number n(n≤200), the number of families willing to participate in the experiment. We consider the families to be indexed from 0 to n−1.

The n remaining lines are such that the i-​th line contains the list of indexes of families the family (i−2) has already visited, separated with spaces.

### Standard output

Print an integer corresponding to the minimum number of families to send to the hotel so that a shuffle of lodging becomes possible.

### Constraints and notes* 2≤n≤200 * The families are indexed from 0 to n-1
* Time limit: 1280 ms
* Memory limit: 136 MB

### Input & Output

input:

```
5
1 2 3
2 3 4
3 4 0
4 0 1
0 1 2
```

output:

```
0
```

input:

```
5
2 3 4
2 3 4
0 1
0 1
0 1
```

output:

```
0
```

input:

```
5
2 3 4
2 3 4
0 1
0 1 2
0 1 2
```

output:

```
1
```