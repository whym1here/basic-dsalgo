#include<bits/stdc++.h>
using namespace std;

template<typename T>
class DSU {
public:
    int n, components;
    vector<T> p, r, s;

    DSU(int _n) {
        n = components = _n;
        r.assign(n, 1);
        s.assign(n, 1);
        p.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    // find the parent of a node x
    T find(T x) {
        assert(0 <= x and x < n);
        T y = x;
        while(x != p[x]) 
            x = p[x];
        while(y != p[y]) {
            T z = p[y];
            p[y] = x;
            y = z;
        }
        return x;
    }

    // join two components of nodes x and y
    bool join(T x, T y) {
        assert(0 <= x and x < n and 0 <= y and y < n);
        x = find(x), y = find(y);
        if(x == y) 
            return false;
        if(p[x] > p[y]) 
            swap(x, y);
        p[y] = x;
        if(p[x] == p[y]) 
            p[y]++;
        s[y] += s[x];
        components--;
        return true;
    }

    // are x and y are in same component
    bool same_group(T x, T y) {
        assert(0 <= x and x < n and 0 <= y and y < n);
        return find(x) == find(y);
    }
    
    // number of nodes in component of x
    T component_size(T x) {
        assert(0 <= x and x < n);
        return s[find(x)];
    }

    // total number of components in the graph
    T components() {
        return components;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}