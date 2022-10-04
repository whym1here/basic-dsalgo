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

# Solution
def solve():
    pass

# Main
for _ in range(inp()):
    solve()
