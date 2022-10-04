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

# Class
class naive_ht:
    def __init__(self, n, m = None) -> None:
        """
        Good constructor for this show case
        """
        self.lookup = [0 for i in range(n)]
        if(m == None):
            self.m = n
        else:
            self.m = m

    def h(self, key):
        """
        Hash function (5051 is a good number)
        """
        return key%(self.m);

    def __getitem__(self, key):
        """
        obj[idx] (getter)
        """
        return self.lookup[self.h(key)]

    def __setitem__(self, key, value):
        """
        obj[idx] = value (setter)
        """
        self.lookup[self.h(key)] = value
    
    def debug(self):
        print(f"lookup = {self.lookup}")

class better_ht:
    def __init__(self, n, m = None) -> None:
        """
        Good constructor for this show case
        """
        self.lookup = [[] for i in range(n)]
        if(m == None):
            self.m = n
        else:
            self.m = m

    def h(self, key):
        return key%(self.m)

    def __getitem__(self, key):
        hkey = self.h(key)
        for i, val in enumerate(self.lookup[hkey]):
            x, y = val[0], val[1]
            if(x == key):
                return y
        self[key] = 0
        return self.lookup[hkey][-1][1]

    def __setitem__(self, key, value):
        hkey = self.h(key)
        ck = True
        for i, val in enumerate(self.lookup[hkey]):
            x, y = val[0], val[1]
            if(x == key):
                ck = False
                self.lookup[hkey][i][1] = value
        if (ck):
            self.lookup[hkey].append([key, value])
    
    def debug(self):
        for i, vali in enumerate(self.lookup):
            print(f"lookup[{i}] = {vali}")
        print()
        

class hashtable:
    def __init__(self, n) -> None:
        self.tempsol = n+1
        self.lookup = [[0, 0] for i in range(n+1)]
    
    def h(self, key):
        m, P, A = 5051, 2000, 8191
        return (((key*A)%P)%m)%(self.tempsol)
    
    def __getitem__(self, key):
        hkey = self.h(key)
        i = hkey
        while(self.lookup[i] != [0, 0]):
            if(self.lookup[i][0] == key):
                return self.lookup[i][1]
            i = (i+1)%(len(self.lookup))
        self[key] = 0
        return self.lookup[-1][1]

    def __setitem__(self, key, value):
        hkey = self.h(key)
        i = hkey
        ck = True
        while(self.lookup[i] != [0, 0]):
            if(self.lookup[i][0] == key):
                ck = False
                self.lookup[i][1] = value
            i = (i+1)%(len(self.lookup))
        if (ck):
            self.lookup[i][0] = key
            self.lookup[i][1] = value
        
    def debug(self):
        print(f"lookup = {self.lookup}")

# Solution
def solve():
    h1 = naive_ht(10, 5150)
    h1[2] = 11
    h1[5150] = 2002
    pr(h1[5150])
    h1.debug()

    h2 = better_ht(11)
    h2[0] = 1
    h2[11] = 2
    h2[22] = 3
    h2[33] = 4
    h2[1] = 11
    h2[12] = 22
    h2[23] = 33
    h2[34] = 44
    print(f"h[34] = {h2[34]}")
    # print(h2[4409])
    h2.debug()

    h3 = hashtable(10)
    t, st = 10, 10
    while(t != 0):
        t -= 1
        h3[st] = st*2
        st += 3
    t, st = 10, 10
    while(t != 0):
        t -= 1
        print(f"[{st}] = {h3[st]}")
        st += 3 
    # h3[25] = 4409
    h3.debug()

# Main
for _ in range(inp()):
    solve()
