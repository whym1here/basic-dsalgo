import os.path
from math import gcd, floor, ceil
from collections import *
import sys
from typing import List
import random 

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

# File Handeling
if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

# Function
def quick_sort(a : List[int], l : int, r : int) -> None:
    if(r - l <= 1):
        return None
    
    idx = random.randint(l, r-1)

    x = a[idx]
    m = l

    for i in range(l, r, 1):
        if (a[i] < x):
            a[i], a[m] = a[m], a[i]
            m += 1

    quick_sort(a, l, m)
    quick_sort(a, m, r)

# Order Statistics : to find array[k] where k is given and an unsorted form of array is given
def find_rnd(a : List[int], l : int, r : int, k : int) -> int:
    if (r - l <= 1):
        return a[k]

    idx =  random.randint(l, r-1)

    x = a[idx]
    m = l

    for i in range(l, r, 1):
        if (a[i] < x):
            a[i], a[m] = a[m], a[i]
            m += 1
    
    if (k < m):
        return find_rnd(a, l, m, k)
    else:
        return find_rnd(a, m, r, k)

# Solution
def solve():
    v1 = [7, 4, 3, 5, 1, 9, 2, 6, 8, 10]
    quick_sort(v1, 0, len(v1))
    pr(v1)

    v2 = [7, 4, 3, 5, 1, 9, 2, 6, 8, 10]
    i = 7
    prl("i = ")
    pr(i)
    prl("find(i) =")
    pr(find_rnd(v2, 0, len(v2), i))

# Main
for _ in range(inp()):
    solve()
