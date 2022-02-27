#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define dbgv(...)
#define dbg(...)
#define dbgr(...)
#define dbgm(...)
#endif

// To generate random number
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<long long>(a, b)(rng)

class Node {
public:
    long long x, y; // x is key and y is priority
    Node * left, * right;
    
    Node(){
        x = y = -1;
        left = right = nullptr;
    }

    Node(long long x = -1, long long y = -1, Node * left = nullptr, Node * right = nullptr){
        this->x = x;
        this->y = y;
        this->left = left;
        this->right = right;
    }

};

class Treap {
public:
    static pair<Node *, Node *> split(Node * node, long long x){
        if(node == nullptr) return make_pair(nullptr, nullptr);

        if(node->x < x){
            auto p = split(node->right, x);
            node->right = p.first;
            return make_pair(node, p.second);
        } else {
            auto p = split(node->left, x);
            node->left = p.second;
            return make_pair(p.first, node); 
        }
    }

    static Node * merge(Node * A, Node * B){
        if(A == nullptr) return B;
        if(B == nullptr) return A;

        if(A->y > B->y){
            A->right = merge(A->right, B);
            return A;
        } else {
            B->left = merge(A, B->left);
            return B;
        }
    }

    // Data Memebrs
    Node * root;
    long long _size;

    Treap(){
        root = nullptr;
        _size = 0;
    }

    long long size(){
        return _size;
    }

    void insert(long long x){
        Node * newNode = new Node(x, uid(1, 1e5));
        root = insert(root, newNode);
        _size++;
    }

    Node * insert(Node * node, Node * newNode){
        if(node == nullptr) return newNode;

        if(newNode->y > node->y){
            auto p = split(node, newNode->x);
            newNode->left = p.first;
            newNode->right = p.second;
            return newNode;
        }

        if(newNode->x < node->x){
            node->left = insert(node->left, newNode);
        } else {
            node->right = insert(node->right, newNode);
        }
        return node;
    }

    bool find(long long x){
        return find(x, root);
    }

    bool find(long long x, Node * node){
        if(node == nullptr) return false;
        if(node->x == x) return true;

        if(node->x < x){
            return find(x, node->right);
        } else {
            return find(x, node->left);
        }
    }

    void remove(long long x){
        if(find(x)){
            root = remove(x, root);
            _size--;
        }
    }

    Node * remove(long long x, Node * node){
        if(node->x == x){
            node = merge(node->left, node->right);
        } else if(node->x < x){
            node->right = remove(x, node->right);
        } else {
            node->left = remove(x, node->left);
        }
        return node;
    }

    void inorder(){
        cout << "inorder : ";
        inorder(root);
        cout << '\n';
    }

    void inorder(Node * node){
        if(node == nullptr){
            return;
        }
        inorder(node->left);
        cout << node->x << " ";
        inorder(node->right);
    }
};

void solve(){
    Treap ths;
    
    vector<int> a = {
        100, 20, 200, 10, 30, 150, 300
    };

    for(auto & x : a){
        ths.insert(x);
    }

    ths.inorder();

    ths.remove(200);

    ths.inorder();

    ths.insert(400);

    ths.inorder();
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    long long T = 1;
    cin >> T; 
    for(long long tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}