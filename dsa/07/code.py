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

# Classes
class single_node:
    def __init__(self, data, next_ptr) -> None:
        self.data = data
        self.next_ptr = next_ptr

class single_linked_list:
    def __init__(self) -> None:
        self.head = single_node(None, None)
    
    def add_after(self, x):
        if(self.head.data == None and self.head.next_ptr == None):
            self.head.data = x
        else:
            temp = self.head
            while(temp.next_ptr != None):
                temp = temp.next_ptr
            obj = single_node(x, None)
            temp.next_ptr = obj

    def traversing(self):
        temp = self.head
        while(temp != None):
            print(f'{temp.data} -> ', end='')
            temp = temp.next_ptr
        print(f'{None}')

class double_node:
    def __init__(self, data, next_ptr, prev_ptr) -> None:
        self.data = data
        self.next_ptr = next_ptr
        self.prev_ptr = prev_ptr
    
class double_linked_list:
    def __init__(self) -> None:
        self.head = double_node(None, None, None)
        self.tail = double_node(None, None, None)
    
    def push_back(self, data):
        if(self.head.data == None):
            self.head.data = data
        elif(self.tail.data == None):
            self.tail.data = data
            self.head.next_ptr = self.tail
            self.tail.prev_ptr = self.head
        else:
            temp = double_node(data, None, None)
            self.tail.next_ptr = temp
            temp.prev_ptr = self.tail
            self.tail = temp
    
    def traversing(self):
        temp = self.head
        while(temp != None):
            print(f'{temp.data} <=> ', end='')
            temp = temp.next_ptr
        print(f'{None}')
    
    def reverse_traversing(self):
        temp = self.tail
        while(temp != None):
            print(f'{temp.data} <=> ', end='')
            temp = temp.prev_ptr
        print(f'{None}')

    def remove(self, x):
        temp = self.head
        while(temp != None and temp.data != x):
            temp = temp.next_ptr
        if(temp.data == x):
            y = temp.prev_ptr
            x = temp
            z = temp.next_ptr
            if(z != None):
                z.prev_ptr = y
            if(y != None):
                y.next_ptr = z
            if(x == self.head):
                self.head = z
            if(temp != None):
                x.next_ptr = None
                x.prev_ptr = None

class Stack:
    def __init__(self) -> None:
        self.head = None
        self.n = 0
    
    def push(self, x):
        temp = single_node(x, self.head)
        self.head = temp
        self.n += 1

    def pop(self):
        if(self.n != 0):
            ans = self.head.data
            self.head = self.head.next_ptr
            self.n -=1
            return ans
        else:
            print("Cannot delete a empty Stack")
            return None
    
    def traversing(self):
        temp = self.head
        while(temp != None):
            print(f'{temp.data} -> ', end='')
            temp = temp.next_ptr
        print(f'{None}')

class Queue:
    def __init__(self) -> None:
        self.head = single_node(None, None)
        self.tail = self.head
        self.n = 0

    def add(self, x):
        if(self.n == 0 and self.head != None):
            self.head.data = x
        elif(self.head == None):
            self.head = single_node(x, None)
            self.tail = self.head
        else:
            temp = single_node(x, None)
            self.tail.next_ptr = temp
            self.tail = temp
        self.n += 1
    
    def remove(self):
        res = self.head
        if(self.n == 0):
            print("Cannot remove element from a empty Queue")
            return None
        else:
            self.n -= 1
            ans = self.head.data
            self.head = self.head.next_ptr
            return ans
    
    def traversing(self):
        temp = self.head
        while(temp != None):
            print(f'{temp.data} -> ', end='')
            temp = temp.next_ptr
        print(f'{None}')        


# Solution
def solve():
    asll = single_linked_list()
    for i in range(1, 11):
        asll.add_after(i)
    asll.traversing()

    adll = double_linked_list()
    for i in range(1, 11):
        adll.push_back(i)
    adll.traversing()
    adll.reverse_traversing()

    for i in range(1, 11):
        adll.remove(i)
        adll.traversing()

    print("Stack")
    st = Stack()
    for i in range(1, 11):
        st.push(i)
    st.traversing()

    for i in range(1, 11):
        print(f'{st.pop()} ', end='')
    print()
    st.traversing()

    st.pop()
    st.push(111)
    st.traversing()

    print("Queue")
    qu = Queue()
    for i in range(1, 11):
        qu.add(i)
    qu.traversing()

    for i in range(1, 11):
        print(f'{qu.remove()} ', end='')
    print()

    qu.traversing()
    qu.remove()
    qu.add(111)
    qu.traversing()

# Main
for _ in range(inp()):
    solve()
