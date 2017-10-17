# Vangelis the Batbear and the Bubbles challenge

<center>Time limit: 1000 ms</center>
<center>Memory limit: 256 MB</center>

Good evening master Wayne.

Joker and his gang attended Black Hat USA 2017 where they learned of a new way on how to damage our city! Specifically, tomorrow night they will try to damage the water pumps of Gotham using bubbles!

The bubbles cause corrosion to the pumps and in a few hours they will damage them with catastrophic results! To dash Joker’s plan, besides stopping him, you need to make sure that the city network does not contain loops.

If Joker manages to inject bubbles to the network and they enter a loop, they will still cause damage to that area even though you would have already arrested Joker and his gang.

Given the map of the water distribution system, you need to make sure that the map does not contain loops.

On the first line there will be an integer <code>t</code>, the number of test cases to follow.

For each test case you will have to write one line that contains an integer, in the case where there is a loop you will write the number 1 or else you will write the number 0.
* 1≤n≤1000 

### Input

```
2
4 5
0 1 0 2 1 2 2 3 0 3
6 5
0 1 0 3 1 2 1 5 3 4
```

### Output

```
1
0
```

### Explanation

Test case #1

Test case #2