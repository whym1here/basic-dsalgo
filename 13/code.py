import os.path
from math import gcd, floor, ceil, inf
from collections import *
import sys

# Constants
mod = 1000000007
INF = float('inf')

# Functions
def st(): return list(sys.stdin.readline().strip())
def li(): return list(map(int, sys.stdin.readline().split()))
def mp(): return map(int, sys.stdin.readline().split())
def inp(): return int(sys.stdin.readline())
def pr(n): return sys.stdout.write(str(n)+"\n")
def prl(n): return sys.stdout.write(str(n)+" ")

# File Handling
if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

# Class
class Graph:
    def __init__(self, n) -> None:
        self.adj_list = [[] for i in range(n)]
    
    def add(self, u, v, wt):
        self.adj_list[u].append([v, wt])
        self.adj_list[v].append([u, wt])
    
    def display(self):
        for i in range(len(self.adj_list)):
            print(f'# node : {i}')
            for j in range(len(self.adj_list[i])):
                print(f'node : {self.adj_list[i][j][0]} wt : {self.adj_list[i][j][1]}')

# Function
class ques01:
    @staticmethod
    def traveling_salesman(gr):
        n = len(gr.adj_list)
        rows, cols = (1<<n), n
        dp = [[INF for i in range(cols)] for j in range(rows)]

        # Base Case
        for i in range(n):
            dp[(1<<i)][i] = 0

        for x in range(1, (1<<n)):
            for v in range(n):
                for u_wt in gr.adj_list[v]:
                    u, wt = u_wt[0], u_wt[1]
                    if((x&(1<<u)) == 0):
                        y = x | (1<<u)
                        dp[y][u] = min(
                            dp[y][u], dp[x][v] + wt
                        )
        res = INF
        for v in range(n):
            res = min(
                res, dp[(1<<n)-1][v]
            )
        return res   

# Solution
def solve():
    n = 8
    g = Graph(n)

    g.add(0, 1, 3)
    g.add(0, 2, 4)
    g.add(0, 3, 7)

    g.add(1, 2, 2)
    g.add(1, 4, 5)

    g.add(2, 4, 2)
    g.add(2, 5, 3)

    g.add(3, 5, 5)
    g.add(3, 6, 6)

    g.add(4, 5, 3)
    g.add(4, 7, 8)

    g.add(5, 6, 7)

    g.add(6, 7, 5)

    g.display()

    print(ques01.traveling_salesman(g))
    

# Main
for _ in range(inp()):
    solve()
