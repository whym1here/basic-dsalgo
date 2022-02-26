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

namespace basic {
    
    class Node {
    public:
        long long data;
        Node * lf, * rt;

        Node(){
            data = 0;
            lf = nullptr;
            rt = nullptr;
        }

        Node(long long x = 0LL, Node * l = nullptr, Node * r = nullptr){
            data = x;
            lf = l;
            rt = r;
        }

        Node * get_left(){
            return lf;
        }

        Node * get_right(){
            return rt;
        }

        long long get_data(){
            return data;
        }

        void set_left(Node * l){
            lf = l;
        }

        void set_right(Node * r){
            rt = r;
        }

        void set_data(long long x){
            data = x;
        }
    };

    class BST {
    private:
        Node * insert(Node * top, long long x){
            if(top == nullptr){
                Node * temp = new Node(x);
                return temp;
            } else {
                if(top->data == x){
                    return top; // only one copy of element stays in BST
                } else if(top->data < x){
                    top->rt = insert(top->get_right(), x);
                    return top; 
                } else {
                    top->lf = insert(top->get_left(), x);
                    return top;
                }
            }
        }

        bool find(Node * top, long long x){
            if(top == nullptr){
                return false;
            } else {
                if(top->data == x){
                    return true;
                } else if(top->data < x){
                    return find(top->get_right(), x);
                } else {
                    return find(top->get_left(), x);
                }
            }
        }

        Node * remove(Node * top, long long x){
            if(top->data == x){
                Node * lf = top->get_left();
                Node * rt = top->get_right();
                if(lf == nullptr){
                    return rt;
                } else if(rt == nullptr){
                    return lf;
                } else {
                    dbg("WHAT");

                    Node * f = top->get_left();
                    if(f->rt == nullptr){
                        top->data = f->data;
                        top->lf = nullptr;
                        return top;
                    } else {
                        while(f->rt->get_right() != nullptr){
                            f = f->get_right();
                        }
                        top->data = f->rt->get_data();
                        f->rt = nullptr;
                        return top;
                    }
                }
            } else {
                if(top->data < x){
                    top->rt = remove(top->get_right(), x);
                    return top;
                } else {
                    top->lf = remove(top->get_left(), x);
                    return top;
                }
            }
        }

        void inorder(Node * top){
            if(top == nullptr){
                return;
            }
            inorder(top->get_left());
            cout << top->get_data() << " ";
            inorder(top->get_right());
        }
    public:
        Node * root;
        long long _size;

        BST(){
            root = nullptr;
            _size = 0;
        } 

        void insert(long long x){
            _size++;
            root = insert(root, x);
        }

        long long size(){
            return _size;
        }

        bool find(long long x){
            return find(root, x);
        }

        void remove(long long x){
            if(find(x)){
                root = remove(root, x);
            } 
        }

        void inorder(){
            cout << "inorder : ";
            inorder(root);
            cout << '\n';
        }
    };
};

namespace advance {
    class Node {
    public:
        long long data;
        Node * lf, * rt;
        long long height;

        Node(){
            data = 0;
            lf = nullptr;
            rt = nullptr;
            height = 0;
        }

        Node(long long x = 0LL, Node * l = nullptr, Node * r = nullptr, long long h = 0){
            data = x;
            lf = l;
            rt = r;
            height = h;
        }

        Node * get_left(){
            return lf;
        }

        Node * get_right(){
            return rt;
        }

        long long get_data(){
            return data;
        }

        long long get_height(){
            return height;
        }

        void set_left(Node * l){
            lf = l;
        }

        void set_right(Node * r){
            rt = r;
        }

        void set_data(long long x){
            data = x;
        }

        void set_height(long long h){
            height = h;
        }
    };

    class AVL {
        public:
        // Need to implememt this
    };

};

void solve(){
    basic::BST bst;
    vector<int> a = {
        100, 20, 200, 10, 30, 150, 300
    };

    for(auto & x : a){
        bst.insert(x);
    }
    bst.inorder();

    bst.remove(200);

    bst.inorder();
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