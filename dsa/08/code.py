import os.path
from math import gcd, floor, ceil
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

# Classes
class slowdsu:
    @staticmethod
    def join(x, y, p):
        x, y = slowdsu.find(x, p), slowdsu.find(y, p)
        for i in range(len(p)):
            if (p[i] == x):
                p[i] = y
         

    @staticmethod
    def find(x, p):
        if(x > len(p)):
            print("Element not in list")
            return None
        return p[x]

class middsu:
    @staticmethod
    def join(x, y, p, lst):
        x, y = middsu.find(x, p), middsu.find(y, p)
        if len(lst[x]) > len(lst[y]):
            x, y = y, x
        for i in lst[x]:
            p[i] = y
            lst[y].append(i)
        lst[x].clear()

    @staticmethod
    def find(x, p):
        return slowdsu.find(x, p)

class fastdsu:
    @staticmethod
    def join(x, y, p, r):
        x, y = fastdsu.find(x, p), fastdsu.find(y, p)
        if(r[x] > r[y]):
            x, y = y, x
        p[x] = y
        if(r[x] == r[y] and x != y):
            r[y] += 1

    @staticmethod
    def find(x, p):
        if(x > len(p)):
            print("Element not in list")
            return None
        y = x
        while(p[y] != y):
            y = p[y]
        while(p[x] != x):
            z = p[x]
            p[x] = y
            x = z
        return x

# Solution
def solve():
    print("\t\tSLOWDSU")
    p1 = [i for i in range(8)]
    print(p1)
    slowdsu.join(1, 2, p1)
    slowdsu.join(1, 5, p1)
    slowdsu.join(7, 4, p1)
    slowdsu.join(3, 6, p1)
    print(p1)
    print("---------------------------------")

    print("\t\tMIDDSU")
    p2 = [i for i in range(8)]
    lst1 = [[i] for i in range(8)]
    print(p2)
    print(lst1)
    middsu.join(1, 2, p2, lst1)
    middsu.join(1, 5, p2, lst1)
    middsu.join(7, 4, p2, lst1)
    middsu.join(3, 6, p2, lst1)
    print(p2)
    print(lst1)
    print("---------------------------------")

    print("\t\tFASTDSU")
    p3 = [i for i in range(8)]
    r1 = [1 for i in range(8)]
    fastdsu.join(1, 2, p3, r1)
    fastdsu.join(1, 5, p3, r1)
    fastdsu.join(7, 4, p3, r1)
    fastdsu.join(3, 6, p3, r1)
    print(p3)
    print(r1)
    print("---------------------------------")

# Main
for _ in range(inp()):
    solve()
