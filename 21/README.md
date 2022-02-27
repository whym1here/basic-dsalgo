# Treaps (Cartesian tree)
- **Tree + Heap = Treap**  
- X values are **keys**
- Y values are **priorotoes**
- It is a way to balance BST and is called **randomized binary serach tree**

## Operations
- **Insert(X,Y)** $O(\log(n))$  
Adds a new node to the tree. One possible variant is to pass only X and generaate Y randomly inside the operation.
- **Search(X)** $O(\log(n))$  
Looks for a node with the specifed key value X. Same as for BST.
- **Erase(X)** $O(\log(n))$  
Looks for a node with the specified value X and removes it from the tree.
- **Union(T1,T2)** $O(m.\log(\frac{n}{m}))$  
Merges two trees, assuming that all the elements are different. It is possbile to achieve the same complexity if duplicate elements should be removed during the merge.
- **Intersect(T1,T2)** $O(m.\log(\frac{n}{m}))$  
Finds the intersection of two tree(i.e. thire common elements). We will not consider the implementation of this operation here. 


## Links
- [CP Algorithms](https://cp-algorithms.com/data_structures/treap.html)
- [GFG](https://www.geeksforgeeks.org/treap-set-2-implementation-of-search-insert-and-delete/)
- [Medium](https://medium.com/carpanese/a-visual-introduction-to-treap-data-structure-part-1-6196d6cc12ee)