#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> p, r, sz;
    int n;

    DSU() {
        n = 0;
    }
    
    DSU(int _n) {
        n = _n;
        p = r = sz = vector<int>(n, 1);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    
    int find(int x) {
        assert(0 <= x and x < n);
        int y = x;
        while(x != p[x]) x = p[x];
        while(y != p[y]) {
            int z = p[y];
            p[y] = x;
            y = z;
        }
        return x;
    }
    
    void join(int x, int y) {
        assert(0 <= x and x < n and 0 <= y and y < n);
        x = find(x), y = find(y);
        if(x == y) return;
        if(r[x] > r[y]) swap(x, y); // for rank heuristics
        // if(sz[x] > sz[y]) swap(x, y); // to size heuristics
        p[x] = y;
        sz[y] += sz[x];
        r[y] += r[x] == r[y];
    }
};

// TODO: 
// 1. Add min, max to each components
// 2. Find the total number of components in O(1)
// 3. Make it more general using ids and template

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}