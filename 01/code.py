import os.path
from math import gcd, floor, ceil
from collections import *
import sys
from typing import List

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

# Functions
def insertion_sort(lst : List[int]) -> None:
    for i in range(1, len(lst)):
        j = i
        while(j > 0 and lst[j] < lst[j-1]):
            lst[j], lst[j-1] = lst[j-1], lst[j]
            j -= 1

# Solution
def solve():
    some = [8, 9, 12, 4, 1, 5 ,6 ]
    insertion_sort(some)
    pr(some)

# Main
for _ in range(inp()):
    solve()
