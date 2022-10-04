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

# Function
def levenshtein_distance(A, B):
    dp = [[0 for i in range(len(B)+1)] for j in range(len(A)+1)]
    for i in range(len(A)+1):
        for j in range(len(B)+1):
            if(i == 0 or j == 0):
                dp[i][j] = i+j
                continue
            if(A[i-1] == B[j-1]):
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(
                    dp[i-1][j-1], dp[i-1][j], dp[i][j-1]
                )
    return dp[len(A)][len(B)]

def txt_align(w, L):
    n = len(w)
    dp = [0 for i in range(n+1)]
    for i in range(1, n+1):
        dp[i] = float('inf')
        s = 0
        for k in range(1, i+1):
            s += w[i-k]
            if(s > L):
                break
            dp[i] = min(
                dp[i], dp[i-k] + ((L-s)*(L-s)*(L-s))
            )
    return dp[n]

# Solution
def solve():
    print(levenshtein_distance(
        "apple", "alpine"
    ))

    print(levenshtein_distance(
        "document", "docament"
    ))

    print(txt_align(
        [1, 2, 4, 6, 7, 8, 7, 4, 3, 2, 1, 3, 6, 7, 7, 5, 5],
        10
    ))

# Main
for _ in range(inp()):
    solve()
