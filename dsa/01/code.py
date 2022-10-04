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

def merge_sub(a : List[int], b : List[int]) -> List[int]:
    n = len(a)
    m = len(b)
    i, j, k = 0, 0, 0
    c = [ 0 for i in range(n+m)]

    while(i < n or j < m):
        if(j == m or (i < n and a[i] < b[j])):
            c[k] = a[i]
            k += 1
            i += 1
        else:
            c[k] = b[j]
            k += 1
            j += 1
    
    return c

def merge_sort(a : List[int]) -> List[int]:
    n = len(a)

    if(n < 2):
        return a
    
    b = [ 0 for i in range(n//2)]
    c = [ 0 for i in range(n - n//2)]

    for i in range(n):
        if (i < n//2):
            b[i] = a[i]
        else:
            c[i-(n//2)] = a[i]
    
    return merge_sub(merge_sort(b), merge_sort(c)) 


# Solution
def solve():
    some = [8, 9, 12, 4, 1, 5 ,6 ]
    pr(some)
    insertion_sort(some)
    pr(some)
    some = [5, 6, 7, 2, 1, 3, 99, 5, 9, 11, 0, 4, 8]
    pr(some)
    some = merge_sort(some)
    pr(some)

# Main
for _ in range(inp()):
    solve()
