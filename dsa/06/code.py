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

#Class
class Stack:
    def __init__(self) -> None:
        self.stack = []
    
    def push(self, x : int) -> None:
        self.stack.append(x)
    
    def pop(self) -> int:
        return self.stack.pop()
    
    def empty(self) -> bool:
        if (len(self.stack) == 0):
            return True
        else:
            return False

class Queue:
    def __init__(self) -> None:
        self.s1 = Stack()
        self.s2 = Stack()
    
    def add(self, x : int) -> None:
        self.s2.push(x)
    
    def remove(self) -> int:
        while not self.s2.empty():
            self.s1.push(self.s2.pop())
        return self.s1.pop()


# Solution
def solve():
    s1 = Stack()
    for i in range(1, 11):
        s1.push(i*i)
        pr(s1.stack)
    
    for i in range(1, 11):
        prl(s1.pop())
        pr(s1.stack)
    
    q1 = Queue()
    for i in range(1, 11):
        q1.add(i*i)
    
    for i in range(1, 11):
        prl(q1.remove())
        

# Main
for _ in range(inp()):
    solve()
