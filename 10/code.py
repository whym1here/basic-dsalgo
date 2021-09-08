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
class navie:
    @staticmethod
    def fabonacci(n : int) -> int:
        if (n < 3):
            return 1
        else :
            return navie.fabonacci(n-1) + navie.fabonacci(n-2)

class fast:
    @staticmethod
    def fabonacci(n : int) -> int:
        res = [0 for i in range(n+1)]
        if(n > 0):
            res[1] = 1
        if(n > 1): 
            res[2] = 1
        for i in range(3, n+1):
            res[i] = res[i-1] + res[i-2]
        return res[n]

class ques01:
    @staticmethod
    def sol(n : int) -> int:
        dp = [None for i in range(n+1)]
        dp[0] = 1
        dp[1] = 1

        for i in range(2, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        
        return dp[n]

class ques02:
    @staticmethod
    def sol(n : int) -> int:
        if (n == 0):
            return 1
        elif (n == 1):
            return 2
        
        dp = [0 for i in range(n+1)]
        dp[0] = 1
        dp[1] = 2

        for i in range(2, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        
        return dp[n]

class ques03:
    @staticmethod
    def sol(n : int) -> int:
        if (n == 0):
            return 1
        elif (n == 1):
            return 2
        elif (n == 2):
            return 2
        
        dp = [0 for i in range(n+1)]
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2

        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
        
        return dp[n]

class ques04:
    @staticmethod
    def slow_sol(n : int, k : int) -> int:
        dp = [0 for i in range(n+1)]
        dp[0] = 1
        
        for i in range(1, n+1):
            for j in range(1, k+1):
                if (i-j >= 0):
                    dp[i] += dp[i-j]
                else:
                    break
        
        return dp[n]

    @staticmethod
    def fast_sol(n : int, k : int) -> int:
        dp = [0 for i in range(n+1)]
        presum = [0 for i in range(n+1)]
        
        dp[0] = 1
        presum[0] = dp[0]

        for i in range(1, n+1):
            if(i-k-1 < 0):
                dp[i] = presum[i-1]
                presum[i] = presum[i-1] + dp[i]
            else:
                dp[i] = presum[i-1] - presum[i-k-1]
                presum[i] = presum[i-1] + dp[i]

        return dp[n]

class ques05:
    @staticmethod
    def sol(costs) -> int:
        n = len(costs)
        if (n == 1):
            return costs[0]
        elif (n == 2):
            return costs[1]+costs[0]
        
        dp = [0 for i in range(n)]

        for i in range(2, n):
            dp[i] = min(dp[i-1], dp[i-2]) + costs[i]
        
        return dp[n-1]

class ques06:
    @staticmethod
    def slow_sol(costs, k):
        n = len(costs)
        dp = [0 for i in range(n)]

        for i in range(1, n):
            dp[i] = 1_000_000_000
            for j in range(1, k+1):
                if(i-j >= 0):
                    dp[i] = min(dp[i], dp[i-j])+costs[i]
        
        return dp[n-1]
    
    @staticmethod
    def fast_sol(costs, k):
        # INCOMPLETE
        return 0

class ques07:
    @staticmethod
    def sol(costs, k):
        n = len(costs)
        dp = [0 for i in range(n)]
        p = [0 for i in range(n)]
        dp[0] = costs[0]
        p[0] = -1
        for i in range(1, n):
            dp[i] = 1_000_000_000
            for j in range(1, k+1):
                if(i-j >= 0):
                    if(dp[i] > dp[i-j] + costs[i]):
                        dp[i] = dp[i-j] + costs[i]
                        p[i] = i-j

        path = []
        x = n-1
        while(x != -1):
            path.append(x)
            x = p[x]
        p = p[::-1]
        return (dp[n-1], path)

class ques08:
    @staticmethod
    def sol(cost):
        n = len(cost)
        m = len(cost[0])
        dp = [[0 for j in range(m+1)] for i in range(n+1)]
        for i in range(1, n+1):
            for j in range(1, m+1):
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + cost[i-1][j-1]
        
        return dp[n][m]

class ques09:
    @staticmethod
    def slow_sol(n : int) -> int:
        dp = [[0 for j in range(n+1)] for i in range(n+1)]

        for i in range(n+1):
            dp[0][i] = 1
            dp[i][0] = 1
        
        for i in range(1, n+1):
            for j in range(1, n+1):
                for k in range(1, j+1):
                    if(i-k >= 0):
                        dp[i][j] += dp[i-k][k]
        
        return dp[n][n]

# Solution
def solve():
    pass

# Main
for _ in range(inp()):
    solve()
