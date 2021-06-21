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

# Function
def insert_heap(h : List[int], x : int) -> None:
    h.append(x)
    n = len(h)
    i = n-1

    while(i > 0 and h[i] < h[(i-1)//2]):
        h[i], h[(i-1)//2] = h[(i-1)//2], h[i]
        i = (i-1)//2

def remove_min(h : List[int]) -> int:
    n = len(h)
    last_element = h[0]

    h[0], h[n-1] = h[n-1], h[0]
    h.pop()
    n = len(h)

    i, j = 0, 0

    while(2*i+1 < n):
        j = 2*i+1
        if((2*i+2 < n) and h[2*i+2] < h[j]):
            j = 2*i+2
        if(h[i] <= h[j]):
            break
        h[i], h[j] = h[j], h[i]
        i = j
    
    return last_element

def heap_sort(a : List[int]) -> None:
    temp = []

    for i in a:
        insert_heap(temp, i)
    
    for i in range(len(a)):
        a[i] = remove_min(temp)

def shift_up(h : List[int], idx : int) -> None:
    while(idx > 0 and h[(idx-1)//2] > h[idx]):
        h[(idx-1)//2], h[idx] = h[idx], h[(idx-1)//2]
        idx = (idx-1)//2

def shift_down(h : List[int], idx : int) -> None:
    n = idx + 1
    i, j = 0, 0

    while(2*i+1 < n):
        j = 2*i+1
        if((2*i+2 < n) and h[2*i+2] < h[j]):
            j = 2*i+2
        if(h[i] <= h[j]):
            break
        h[i], h[j] = h[j], h[i]
        i = j
        
def memory_eff_heap_sort(a : List[int]) -> None:
    n = len(a)

    for i in range(n):
        shift_up(a, i)

    for i in range(n-1, 0, -1):
        a[0], a[i] = a[i], a[0]
        shift_down(a, i-1)

    a.reverse()

# Solution
def solve():
    a, b = [], [26, 15, 2, 5, 8, 9, 7, 13, 15, 10]

    for i in b:
        insert_heap(a, i)
    pr(a)

    t = 10
    while(t):
        t -= 1
        val = remove_min(a)
        pr(val)

    some = [11, 34, 66, 656, 453, 33, 66, 21, 1, 8, 7, 3 ,6]
    heap_sort(some)
    pr(some)

    some1 = [11, 34, 66, 656, 453, 33, 66, 21, 1, 8, 7, 3 ,6]
    memory_eff_heap_sort(some1)
    pr(some1)

# Main
for _ in range(inp()):
    solve()
