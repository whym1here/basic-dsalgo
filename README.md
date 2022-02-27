![logo](logo.png)

<img alt="C++" src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
<img alt="Python" src="https://img.shields.io/badge/python-%2314354C.svg?style=for-the-badge&logo=python&logoColor=white"/>
<img alt="Visual Studio Code" src="https://img.shields.io/badge/VisualStudioCode-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white"/>
<img alt="Vim" src="https://img.shields.io/badge/VIM-%2311AB00.svg?style=for-the-badge&logo=vim&logoColor=white"/>
<img alt="Ubuntu" src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white" />


### Implemented :
1. Basic Sorting
    - [x] Insertion Sort ```O(n^2)```
    - [x] Merge Sort with Merge method ```O(nlog(n))```
2. Heaps and Sorting 
    - [x] Insert into heap ```O(log(n))``` 
    - [x] Delete minimum element from heap ```O(log(n))```
    - [x] Shift up and Shift down for Binary Tree ```O(log(n))```
    - [x] Normal and memory efficient Heap Sort ```O(nlog(n))```
3. Quick Sort and Order Statistics
    - [x] Quick Sort ```O(nlog(n))```
    - [x] Order Statistics ```O(n)```
4. Radix and Counting Sort
    - [x] Radix Sort ```O(d*(n+b))```
    - [x] Counting Sort ```O(n+k)```
5. Binary Search and its application for sorted array
    - [x] Binary Search ```O(log(n))```
    - [x] minimun i such that a[i] >= x ```O(log(n))```
    - [x] maximum i such that a[i] <= x ```O(log(n))```
6. Stack and Queue using arrays and dynamic memory allocation
    - [x] Stack push ```O(n) and amortized O(1)```
    - [x] Stack pop ```O(n) and amortized O(1)```
    - [x] Queue add ```O(n) and amortized O(1)```
    - [x] Queue remove ```O(n) and amortized O(1)```
7. Linked lists, Stack and Queue
    - [x] Single Linked List append ```O(n)```
    - [x] Single Linked List remove ```O(n)```
    - [x] Doubly Linked List append ```O(n)```
    - [x] Doubly Linked List remove ```O(n)```
    - [x] Stack push ```O(1)```
    - [x] Stack pop ```O(1)```
    - [x] Queue add ```O(1)```
    - [x] Queue remove ```O(1)```
8. Disjoint Sets
    - [x] slow join ```O(n) and Total : O(n^2)```
    - [x] slow find ```O(1)``` 
    - [x] medium join ```O(n) and Total : O(nlog(n))```
    - [x] medium find ```O(1)```
    - [x] fast join ```O(n) and Total : O(inverse-ackermann_function(n, m))```
    - [x] fast find ```O(n) and amortized O(1)```
9. Fibonacci Heap 
    - [ ] add ```O(1)```
    - [ ] remove_min(x) ```amortized O(log(n))```
    - [ ] merge(H1, h2) ```O(1)```
    - [ ] decrease_key(x, y) ```amortized O(1)```
10. Dynamic Programming Part - 01
    - [x] GrassHopper Problem with different variations
    - [x] Turtle Problem
11. Dynamic Programming Part - 02
    - [x] Levenshtein Distance(Edit Distance) ```O(|A|.|B|)```
    - [x] Text Alignment for Printing  ```O(n^2)```
    - [ ] Run-Length Encoding(RLE)
12. Knapsack Problem
    - [x] 0-1 Knapsack with wt[i] = cost[i] ```O(n.S)```
    - [x] 0-1 Knapsack with ```O(n.S)```
    - [x] 0-1 Knapsack with bits ```O((2^n).n)```
    - [x] faster 0-1 Knapsack with bits ```O((2^(n/2)).n)```
    - [x] Subset Sum ```O(n.S)```
    - [ ] Multiple Knapsack
13. Dynamic Programming on Profiles
    - [x] Traveling Salesman Problem ```O(n.(2^(n).k)```
    - [ ] Full Profile Parquet Problem 
    - [ ] Broken Profile Parquet Problem
    - [ ] Variation on Parquet Problem
14. Hash Table
    - [x] get(key) ```O(n) and amortized O(1)```
    - [x] put(key, value) ```O(n) and amortized O(1)```
15. Advance Hashing
    - [ ] Perfect Hashing
    - [ ] Cuckoo Hashing
    - [ ] Bloom Filter
    - [ ] Cuckoo Filter
16. Segment Tree for add and min
    - [x] set(index, value) ```O(log(n))```
    - [x] operation(left_index, right_index) ```O(log(n))```
17. Segment Tree with lazy propogation
    - [x] set(index, value) ```O(log(n))```
    - [x] get(left_index, right_index) ```O(log(n))```
    - [x] range_update(left_index, right_index, value) ```O(log(n))```
18. Fenwick Tree and Sparse Table
    - [x] Fenwick Tree increment(index, value) ```O(log(n))```
    - [x] Fenwick Tree query(left_index, right_index) ```O(log(n))```
    - [x] Sparse Table building(size) ```O(nlog(n))```
    - [x] Sparse Table query(left_index, right_index) ```O(1)```
19. 2D Segment Tree, Fenwick Tree, Sparse Table and Sweep Line Algorithm
    - [x] 2D Segment Tree insert(i, j, val) ```O(2.m.log(n).log(m))``` 
    - [x] 2D Segment Tree query(l, r, b, t) ```O(log(n).log(m))``` 
    - [x] 2D Fenwick Tree increment(i, j, v) ```O(log(n).log(m))```
    - [x] 2D Fenwick Tree query(l, r, b, t) ```O(log(n).log(m))```
    - [ ] 2D Sparse Table building(size) ```O(n.m.log(n).log(m))```
    - [ ] 2D Sparse Table query(l, r, b, t) ```O(1)```
    - [ ] Sweep Line Algorithm
20. Binary Search Tree
    - [x] BST insert(key) ```O(h)```
    - [x] BST find(key) ```O(h)```
    - [x] BST remove(key) ```O(h)```
    - [ ] AVL tree insert(key) ```O(log(n))```
    - [ ] AVL tree find(key) ```O(log(n))```
    - [ ] AVL tree remove(key) ```O(log(n))```
21. Treap
    - [x] split(node, key) ```O(log(n))```
    - [x] merge(A, B) ```O(log(n))```
    - [x] insert(key) ```O(log(n))```
    - [x] find(key) ```O(log(n))```
    - [x] remove(key) ```O(log(n))```