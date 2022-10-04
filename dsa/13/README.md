# Questions

## Traveling Salesman Problem
Start form city S and visit all the other cities in some order which has total minimum distance travelled.

NOTE : In Graph Theory this is known as hamiltonian path i.e. it is a path which visits all the vertices exactly once.

```
node : (node, weight)
```

```py
0 : (1, 3), (2, 4), (3, 7)
1 : (0, 3), (2, 2), (4, 5)
2 : (0, 4), (1, 2), (4, 2), (5, 3)
3 : (0, 7), (5, 5), (6, 6)
4 : (1, 5), (2, 2), (5, 3), (7, 8)
5 : (2, 3), (3, 5), (4, 3), (6, 7)
6 : (3, 6), (5, 7), (7, 5)
7 : (4, 8), (6, 5)
```

## Parquet Problem (DP on Profiles)
Given a grid of size n x m . Find number of ways to fill the grid with figures of size 2 x 1 (no no cell should be left unfilled, and figures should not overlap each other).

- T or test cases on first line
- n and m on second line

### Input :
```
4
8 9
6 8
4 5
3 4
```

### Output :
```
108435745
167089
95
11
```

## Variation on Parquet Problem
Number of ways to color a grid of n x m in such a way that there are no 2 x 2 that have same color in all 4 cells.
