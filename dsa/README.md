# Data Structures and Algorithms

### Implemented:
1. [Basic Sorting](01)
    - [x] Insertion Sort ```O(n^2)```
    - [x] Merge Sort with Merge method ```O(nlog(n))```
2. [Heaps and Sorting](02) 
    - [x] Insert into heap ```O(log(n))``` 
    - [x] Delete minimum element from heap ```O(log(n))```
    - [x] Shift up and Shift down for Binary Tree ```O(log(n))```
    - [x] Normal and memory efficient Heap Sort ```O(nlog(n))```
3. [Quick Sort and Order Statistics](03)
    - [x] Quick Sort ```O(nlog(n))```
    - [x] Order Statistics ```O(n)```
4. [Radix and Counting Sort](04)
    - [x] Radix Sort ```O(d*(n+b))```
    - [x] Counting Sort ```O(n+k)```
5. [Binary Search and its application for sorted array](05)
    - [x] Binary Search ```O(log(n))```
    - [x] minimun i such that a[i] >= x ```O(log(n))```
    - [x] maximum i such that a[i] <= x ```O(log(n))```
6. [Stack and Queue using arrays and dynamic memory allocation](06)
    - [x] Stack push ```O(n) and amortized O(1)```
    - [x] Stack pop ```O(n) and amortized O(1)```
    - [x] Queue add ```O(n) and amortized O(1)```
    - [x] Queue remove ```O(n) and amortized O(1)```
7. [Linked lists, Stack and Queue](07)
    - [x] Single Linked List append ```O(n)```
    - [x] Single Linked List remove ```O(n)```
    - [x] Doubly Linked List append ```O(n)```
    - [x] Doubly Linked List remove ```O(n)```
    - [x] Stack push ```O(1)```
    - [x] Stack pop ```O(1)```
    - [x] Queue add ```O(1)```
    - [x] Queue remove ```O(1)```
8. [Disjoint Sets](08)
    - [x] slow join ```O(n) and Total : O(n^2)```
    - [x] slow find ```O(1)``` 
    - [x] medium join ```O(n) and Total : O(nlog(n))```
    - [x] medium find ```O(1)```
    - [x] fast join ```O(n) and Total : O(inverse-ackermann_function(n, m))```
    - [x] fast find ```O(n) and amortized O(1)```
9. [Fibonacci Heap](09) 
    - [ ] add ```O(1)```
    - [ ] remove_min(x) ```amortized O(log(n))```
    - [ ] merge(H1, h2) ```O(1)```
    - [ ] decrease_key(x, y) ```amortized O(1)```
10. [Dynamic Programming Part - 01](10)
    - [x] GrassHopper Problem with different variations
    - [x] Turtle Problem
11. [Dynamic Programming Part - 02](11)
    - [x] Levenshtein Distance(Edit Distance) ```O(|A|.|B|)```
    - [x] Text Alignment for Printing  ```O(n^2)```
    - [ ] Run-Length Encoding(RLE)
12. [Knapsack Problem](12)
    - [x] 0-1 Knapsack with wt[i] = cost[i] ```O(n.S)```
    - [x] 0-1 Knapsack with ```O(n.S)```
    - [x] 0-1 Knapsack with bits ```O((2^n).n)```
    - [x] faster 0-1 Knapsack with bits ```O((2^(n/2)).n)```
    - [x] Subset Sum ```O(n.S)```
    - [ ] Multiple Knapsack
13. [Dynamic Programming on Profiles](13)
    - [x] Traveling Salesman Problem ```O(n.(2^(n).k)```
    - [ ] Full Profile Parquet Problem 
    - [ ] Broken Profile Parquet Problem
    - [ ] Variation on Parquet Problem
14. [Hash Table](14)
    - [x] get(key) ```O(n) and amortized O(1)```
    - [x] put(key, value) ```O(n) and amortized O(1)```
15. [Advance Hashing](15)
    - [ ] Perfect Hashing
    - [ ] Cuckoo Hashing
    - [ ] Bloom Filter
    - [ ] Cuckoo Filter
16. [Segment Tree for add and min](16)
    - [x] set(index, value) ```O(log(n))```
    - [x] operation(left_index, right_index) ```O(log(n))```
17. [Segment Tree with lazy propogation](17)
    - [x] set(index, value) ```O(log(n))```
    - [x] get(left_index, right_index) ```O(log(n))```
    - [x] range_update(left_index, right_index, value) ```O(log(n))```
18. [Fenwick Tree and Sparse Table](18)
    - [x] Fenwick Tree increment(index, value) ```O(log(n))```
    - [x] Fenwick Tree query(left_index, right_index) ```O(log(n))```
    - [x] Sparse Table building(size) ```O(nlog(n))```
    - [x] Sparse Table query(left_index, right_index) ```O(1)```
19. [2D Segment Tree, Fenwick Tree, Sparse Table and Sweep Line Algorithm](19)
    - [x] 2D Segment Tree insert(i, j, val) ```O(2.m.log(n).log(m))``` 
    - [x] 2D Segment Tree query(l, r, b, t) ```O(log(n).log(m))``` 
    - [x] 2D Fenwick Tree increment(i, j, v) ```O(log(n).log(m))```
    - [x] 2D Fenwick Tree query(l, r, b, t) ```O(log(n).log(m))```
    - [ ] 2D Sparse Table building(size) ```O(n.m.log(n).log(m))```
    - [ ] 2D Sparse Table query(l, r, b, t) ```O(1)```
    - [ ] Sweep Line Algorithm
20. [Binary Search Tree](20)
    - [x] BST insert(key) ```O(h)```
    - [x] BST find(key) ```O(h)```
    - [x] BST remove(key) ```O(h)```
    - [ ] AVL tree insert(key) ```O(log(n))```
    - [ ] AVL tree find(key) ```O(log(n))```
    - [ ] AVL tree remove(key) ```O(log(n))```
21. [Treap](21)
    - [x] split(node, key) ```O(log(n))```
    - [x] merge(A, B) ```O(log(n))```
    - [x] insert(key) ```O(log(n))```
    - [x] find(key) ```O(log(n))```
    - [x] remove(key) ```O(log(n))```
22. [Splay Tree](22)
    - [ ] splay(node) ```amortized O(log(n))```
    - [ ] find(key) ```amortized O(log(n))```
    - [ ] insert(key) ```amortized O(log(n))```
    - [ ] remove(key) ```amortized O(log(n))```