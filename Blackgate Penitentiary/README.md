# Blackgate Penitentiary

Vangelis the Batbear trapped all the members of Joker's Streetgang in a basement.

Your job as a police officer is to transport all gang members to Blackgate Penitentiary.

To facilitate the transport, you should form a row such that the heights of the gang members are in non-decreasing order. For each gang member you should find the minimum and the maximum position where they can be in a valid sorted row and produce a roster with this information.### Standard input

Input will start with a line that contains only one integer <code>n</code>, the number of crew members that were arrested. On each of the following <code>n</code> lines there will be a single word <code>s</code> and an integer <code>h</code> separated by a space character, where <code>s</code> is the name and <code>h</code> is the height of the crew member.### Standard output

On the output, there will be <code>g</code> lines. Each line will contain in alphabetical order and space separated the names of the crew members that have the same height, followed by the minimum and the maximum position where any member of the specific group can be placed. The groups should be printed in increasing order of their members' heights.### Constraints and notes* 1≤n≤1000 * 1≤length(si)≤10
* 120≤hi≤250
* Names are only composed of characters of the Latin alphabet.* Time limit: 2500 ms
* Memory limit: 256 MB

### Input & Ouput

input:

```
6
TheJoker 180
HarleyQuin 160
MrHammer 220
Boody 220
Muggs 180
Paulie 180
```

output:

```
HarleyQuin 1 1
Muggs Paulie TheJoker 2 4
Boody MrHammer 5 6
```

input:

```
10
a 200
aa 200
ab 200
aba 200
aaa 200
b 200
A 200
Aa 200
AB 200
B 200
```

output:

```
A AB Aa B a aa aaa ab aba b 1 10
```