# NOT WORKING

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

class segtree1:
    def __init__(self) -> None:
        self.size = None
        self.tree = []
    
    def init(self, n):
        self.size = 1
        while(self.size < n):
            self.size *= 2
        self.tree = [0 for i in range(2*self.size)]

    
    def set(self, i, v):
        self._set(i, v, 0, 0, self.size)

    def _set(self, i, v, x, lx, rx):
        if(rx - lx == 1):
            self.tree[x] = v
            return None # to exit the function (as self.tree[x]...) is illegeal here
        m = (lx + rx)//2
        if(i < m):
            self._set(i, v, 2*x+1, lx, m)
        else:
            self._set(i, v, 2*x+1, m, rx)
        self.tree[x] = self.tree[2*x+1] + self.tree[2*x+2]
        
    def op(self, l, r):
        return self._op(l, r, 0, 0, self.size)
    
    def _op(self, l, r, x, lx, rx):
        if(l >= rx or r <= lx):
            return 0
        if(l <= lx and rx <= r):
            return self.tree[x]
        m = (lx + rx)//2
        s1 = self._op(l, r, 2*x + 1, lx, m)
        s2 = self._op(l, r, 2*x + 2, m, rx)
        return s1 + s2

# Solution
def solve():
    n, m = map(int, input().split())
    st = segtree1()
    st.init(n)
    
    a = list(map(int, input().split()))
    for i, v in enumerate(a):
        st.set(i, v)
    
    for _ in range(m):
        op, var1, var2 = map(int, input().split())
        if(op == 1):
            i, v = var1, var2
            st.set(i, v)
        else:
            l, r = var1, var2
            pr(st.op(l, r))

# Main
# for _ in range(inp()):
solve()
