import os.path
from math import gcd, floor, ceil, trunc
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
class helper:
    @staticmethod
    def binary_search(vp, val):
        # print(vp)
        l = -1
        r = len(vp)
        while(r > l+1):
            m = (r+l)//2
            # print(m)
            # print(f"l = {l}\nr = {r}")
            if(vp[m][0] <= val):
                l = m
            else:
                r = m
        return l

class ques01:
    @staticmethod
    def knapsack(wt, S):
        n = len(wt)
        dp = [[bool(0) for j in range(S+1)] for i in range(n+1)]
        for i in range(0, n+1):
            for j in range(0, S+1):
                if (j == 0):
                    dp[i][j] = True
                elif (i == 0):
                    dp[i][j] = False
                elif (j >= wt[i-1]):
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-wt[i-1]]
                else:
                    dp[i][j] = dp[i-1][j]
        
        for i in range(S, -1, -1):
            if(dp[n][i]):
                return i
        return 0

class ques02:
    @staticmethod
    def knapsack(wt, cost, S):
        n = len(wt)
        dp = [[None for j in range(S+1)] for i in range(n+1)]
        for i in range(0, n+1):
            for j in range(0, S+1):
                if(j == 0):
                    dp[i][j] = 0
                elif(i == 0):
                    dp[i][j] = 0
                elif(j >= wt[i-1]):
                    dp[i][j] = max(
                        dp[i-1][j], cost[i-1]+dp[i-1][j-wt[i-1]]
                    )
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[n][S]

class ques03:
    @staticmethod
    def slow_knapsack(wt, cost, S):
        n = len(wt)
        l = (1<<n)
        res = 0
        for x in range(0, l):
            sw = 0
            sc = 0
            for i in range(0, n):
                if (x&(1<<i)) > 0:
                    sc += cost[i]
                    sw += wt[i]
            if(sw <= S):
                res = max(res, sc)
        return res

    @staticmethod
    def fast_knapsack(wt, cost, S):
        n = len(wt)
        l = (1<<(n//2))
        res = 0
        y_data = []
        for y in range(0, (1<<(n-(n//2)))):
            sw = 0
            sc = 0
            for i in range(0, n-(n//2)):
                if(y&(1<<i)):
                    sc += cost[i+(n//2)]
                    sw += wt[i+(n//2)]
            y_data.append([sw, sc])
        y_data.sort()

        for x in range(0, l):
            sw = 0
            sc = 0
            for i in range(0, n//2):
                if(x&(1<<i) > 0):
                    sc += cost[i]
                    sw += wt[i]
            idx = helper.binary_search(y_data, (S-sw))
            if(idx != -1):
                if(idx == len(y_data)):
                    idx = len(y_data)-1
                res = max(res, sc + y_data[idx][1])
        
        return res

class ques04:
    @staticmethod
    def subset_sum(aset, S):
        n = len(aset)
        dp = [[None for j in range(S+1)] for i in range(n+1)]
        for i in range(0, n+1):
            for j in range(0, S+1):
                if(j == 0):
                    dp[i][j] = True
                elif(i == 0):
                    dp[i][j] = False
                elif(j >= aset[i-1]):
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-aset[i-1]]
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[n][S]
            

# Solution
def solve():
    print(ques01.knapsack(
        [5, 3, 2, 3], 9
    ))
    print()

    print(ques02.knapsack(
        [5, 3, 2, 3],
        [3, 2, 5, 3],
        9
    ))

    print(ques02.knapsack(
        [10, 20, 30],
        [60, 100, 120],
        50
    ))
    
    print(ques02.knapsack(
        [23, 31, 29, 44, 53, 38, 63, 85, 89, 82],
        [92, 57, 49, 68, 60, 43, 67, 84, 87, 72],
        165
    ))

    print(ques02.knapsack(
        [4, 5, 6],
        [1, 2, 3],
        3
    ))

    print(ques02.knapsack(
        [41, 50, 49, 59, 55, 57, 60],
        [442, 525, 511, 593, 546, 564, 617],
        170
    ))

    print()

    print(ques03.slow_knapsack(
        [5, 3, 2, 3],
        [3, 2, 5, 3],
        9
    ))

    print(ques03.slow_knapsack(
        [10, 20, 30],
        [60, 100, 120],
        50
    ))
    
    print(ques03.slow_knapsack(
        [23, 31, 29, 44, 53, 38, 63, 85, 89, 82],
        [92, 57, 49, 68, 60, 43, 67, 84, 87, 72],
        165
    ))

    print(ques03.slow_knapsack(
        [4, 5, 6],
        [1, 2, 3],
        3
    ))

    print(ques03.slow_knapsack(
        [41, 50, 49, 59, 55, 57, 60],
        [442, 525, 511, 593, 546, 564, 617],
        170
    ))

    print()

    print(ques03.fast_knapsack(
        [5, 3, 2, 3],
        [3, 2, 5, 3],
        9
    ))

    print(ques03.fast_knapsack(
        [10, 20, 30],
        [60, 100, 120],
        50
    ))
    
    print(ques03.fast_knapsack(
        [23, 31, 29, 44, 53, 38, 63, 85, 89, 82],
        [92, 57, 49, 68, 60, 43, 67, 84, 87, 72],
        165
    ))

    print(ques03.fast_knapsack(
        [4, 5, 6],
        [1, 2, 3],
        3
    ))

    print(ques03.fast_knapsack(
        [41, 50, 49, 59, 55, 57, 60],
        [442, 525, 511, 593, 546, 564, 617],
        170
    ))

    print()

    print(ques04.subset_sum(
        [3, 34, 4, 12, 5, 2], 9
    ))

    print(ques04.subset_sum(
        [3, 34, 4, 12, 5, 2], 30
    ))

    print(ques04.subset_sum(
        [1, 5, 3, 7, 4], 12
    ))

# Main
for _ in range(inp()):
    solve()
