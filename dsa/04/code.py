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
def counting_sort(arr, place):
    n = len(arr)
    cnt = [0]*(10)
    m = len(cnt)
    sorted_arr = [0]*(n)

    # pr(cnt)
    # pr(sorted_arr)

    for i in range(n):
        cnt[(arr[i]//place)%10] += 1
    
    for i in range(1, m):
        cnt[i] += cnt[i-1]

    # pr(cnt)

    i = n-1
    while(i >= 0):
        idx = (arr[i]//place)%10
        sorted_arr[cnt[idx]-1] = arr[i]
        cnt[idx] -= 1
        i -= 1 

    for i in range(n):
        arr[i] = sorted_arr[i]

def radix_sort(arr):
    uplim = max(arr)
    place = 1
    while(uplim//place > 0):
        counting_sort(arr, place)
        place *= 10

# Solution
def solve():
    a = [44, 232, 3213, 21321, 31233, 323, 1, 3234, 1233, 90324, 4334, 423842, 9324221, 3443258, 99343824]
    pr(a)
    radix_sort(a)
    pr(a)

# Main
for _ in range(inp()):
    solve()
