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

# File Handeling
if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

# Functions 
def basic_binary_search(a, x):
    n = len(a)
    l = 0
    r = n-1
    m = 0
    while(r >= l):
        m = (l+r)//2
        if(a[m] < x):
            l = m+1
        elif(a[m] > x):
            r = m-1
        else:
            return m
    return -1

def left_greater_equal(a, x): # min a[i] >= x
    n = len(a)
    l = -1 
    r = n
    m = 0
    while(r > l+1):
        m = (l+r)//2
        if(a[m] >= x):
            r = m
        else:
            l = m
    return r # returns n if x > a[n-1] 

def right_less_equal(a, x): # max a[i] <= x 
    n = len(a)
    l = -1 
    r = n
    m = 0
    while(r > l+1):
        m = (l+r)//2
        if(a[m] <= x):
            l = m
        else:
            r = m
    return l # returns n if x > a[n-1] 

# Solution
def solve():
    a = [2, 5, 6, 10, 12, 18, 21]
    pr(a)

    pr(basic_binary_search(a, 2))
    pr(basic_binary_search(a, 21))
    pr(basic_binary_search(a, 12))
    pr(basic_binary_search(a, 4))
    pr(' ')

    pr(left_greater_equal(a, 2))
    pr(left_greater_equal(a, 21))
    pr(left_greater_equal(a, 12))
    pr(left_greater_equal(a, 4))
    pr(left_greater_equal(a, 7))
    pr(left_greater_equal(a, 15))
    pr(left_greater_equal(a, 1))
    pr(left_greater_equal(a, 50))
    pr(' ')

    pr(right_less_equal(a, 2))
    pr(right_less_equal(a, 21))
    pr(right_less_equal(a, 12))
    pr(right_less_equal(a, 4))
    pr(right_less_equal(a, 7))
    pr(right_less_equal(a, 15))
    pr(right_less_equal(a, 1))
    pr(right_less_equal(a, 50))
    pr(' ')

# Main
for _ in range(inp()):
    solve()
