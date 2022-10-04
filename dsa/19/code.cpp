#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#else
#define dbgv(...)
#define dbg(...)
#define dbgr(...)
#define dbgm(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<long long>(a, b)(rng)

class Point {
public:
    long long x, y;

    Point(){
        Point(-1, -1);
    }

    Point(long long x, long long y){
        this->x = x;
        this->y = y;
    }
};

class Rectangle {
public:
    Point p1, p2;

    Rectangle(long long x1, long long y1, long long x2, long long y2){
        p1 = Point(x1, y1);
        p2 = Point(x2, y2);
    }

    pair<Point, Point> leftPoint(){
        Point r1 = p1;
        Point r2 = Point(p1.x, p2.y);
        return make_pair(r1, r1);
    }

    pair<Point, Point> rightPoint(){
        Point r1 = Point(p2.x, p1.y);
        Point r2 = p2;
        return make_pair(r1, r2);
    }
};

class segtree{
private:
    void insert(long long i, long long v, long long x, long long lx, long long rx){
        if(rx - lx == 1){
            tree[x] = v;
            return;
        }

        long long m = (lx + rx)/2;
        if(i < m){
            insert(i, v, 2 * x + 1, lx, m);
        } else {
            insert(i, v, 2 * x + 2, m, rx);
        }

        tree[x] = tree[2 * x + 1] + tree[2 * x + 1];
    }

    long long query(long long l, long long r, long long x, long long lx, long long rx){
        if(lazy[x] != 0){
            tree[x] += (rx - lx) * lazy[x];
            propogate(x, lx, rx);
        }

        if(l <= lx and rx <= r){
            return tree[x];
        }        

        if(lx >= r or rx <= l){
            return 0;
        }
        long long m = (lx + rx)/2;
        long long q1 = query(l, r, 2 * x + 1, lx, m);
        long long q2 = query(l, r, 2 * x + 2, m, rx);
        return q1 + q2;
    }

    void build(const vector<long long> & a, long long x, long long lx, long long rx){
        if(rx - lx == 1){
            if(lx < (int)a.size()){
                tree[x] = a[lx];
            }
            return;
        }
        long long m = (lx + rx)/2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 1];
    }

    void range_update(long long l, long long r, long long v, long long x, long long lx, long long rx){
        if(lazy[x] != 0){
            tree[x] += (rx - lx) * lazy[x];
            propogate(x, lx, rx);
        }

        if(l <= lx and rx <= r){
            lazy[x] += v;
            tree[x] += (rx - lx) * v;
            propogate(x, lx, rx);
            return;
        }

        if(lx >= r or rx <= l){
            return;
        }

        long long m = (lx + rx)/2;
        range_update(l, r, v, 2 * x + 1, lx, m);
        range_update(l, r, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void propogate(long long x, long long lx, long long rx){
        if(rx - lx != 1){
            lazy[2 * x + 1] += lazy[x];
            lazy[2 * x + 2] += lazy[x];
        }
        lazy[x] = 0;
    }

public:
    vector<long long> tree, lazy;
    long long size;

    segtree(){}

    segtree(long long n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2 * size, 0LL);
        lazy.assign(2 * size, 0LL);
    }

    segtree(const vector<long long> & a){
        long long n = (int)a.size();

        size = 1;
        while(size < n) size *= 2;
        tree.assign(2 * size, 0LL);
        lazy.assign(2 * size, 0LL);

        build(a, 0, 0, size);
    }

    void insert(long long i, long long v){
        insert(i, v, 0, 0, size);
    }

    long long query(long long l, long long r){
        return query(l, r, 0, 0, size);
    }

    void range_update(long long l, long long r, long long v){
        range_update(l, r, v, 0, 0, size);
    }
};

namespace ques01 {
    // INCOMPLETE
    void solve(long long n, long long m, vector<Rectangle> & rectangles, vector<Point> points){
        segtree cnt(n);
        
    }
}

class segtree2d {
private:

    void insertx(long long i, long long j, long long v, long long x, long long lx, long long rx, long long y, long long ly, long long ry){
        // dbg(make_tuple(i, j, v, x, lx, rx, y, ly, ry));
        if(rx - lx == 1){
            inserty(i, j, v, x, lx, rx, y, ly, ry);
            return;
        }
        long long mx = (lx + rx) / 2;
        if(i < mx){
            insertx(i, j, v, 2 * x + 1, lx, mx, y, ly, ry);
        } else {
            insertx(i, j, v, 2 * x + 2, mx, rx, y, ly, ry);
        }
        for(long long idx = 0; idx < 2 * sizey; idx++){
            tree[x][idx] = tree[2 * x + 1][idx] + tree[2 * x + 2][idx];
        }
    }

    void inserty(long long i, long long j, long long v, long long x, long long lx, long long rx, long long y, long long ly, long long ry){
        // dbg(make_tuple(i, j, v, x, lx, rx, y, ly, ry));
        if(ry - ly == 1){
            tree[x][y] = v;
            return;
        }
        long long my = (ly + ry) / 2;
        if(j < my){
            inserty(i, j, v, x, lx, rx, 2 * y + 1, ly, my);
        } else {
            inserty(i, j, v, x, lx, rx, 2 * y + 2, my, ry);
        }
        tree[x][y] = tree[x][2 * y + 1] + tree[x][2 * y + 2];
    }

    long long queryx(long long l, long long r, long long b, long long t, long long x, long long lx, long long rx, long long y, long long ly, long long ry){
        // dbg(make_tuple(l, r, b, t, x, lx, rx, y, ly, ry));
        if(l <= lx and rx <= r){
            return queryy(l, r, b, t, x, lx, rx, y, ly, ry);
        }
        if(lx >= r or rx <= l){
            return 0;
        }
        long long mx = (lx + ry)/2;
        long long s1 = queryx(l, r, b, t, 2 * x + 1, lx, mx, y, ly, ry);
        long long s2 = queryx(l, r, b, t, 2 * x + 2, mx, rx, y, ly, ry);
        return s1 + s2;
    }

    long long queryy(long long l, long long r, long long b, long long t, long long x, long long lx, long long rx, long long y, long long ly, long long ry){
        // dbg(make_tuple(l, r, b, t, x, lx, rx, y, ly, ry));
        if(b <= ly and ry <= t){
            return tree[x][y];
        }
        if(ly >= t or ry <= b){
            return 0;
        }
        long long my = (ly + ry)/2;
        long long s1 = queryy(l, r, b, t, x, lx, rx, 2 * y + 1, ly, my);
        long long s2 = queryy(l, r, b, t, x, lx, rx, 2 * y + 2, my, ry);
        return s1 + s2;
    }

public:
    vector<vector<long long>> tree;
    long long sizex, sizey;

    // segtree2d() {}

    segtree2d(long long n, long long m){
        sizex = 1, sizey = 1;
        while(sizex < n) sizex *= 2;
        while(sizey < m) sizey *= 2;
        tree.assign(2 * sizex, vector<long long>(2 * sizey, 0));
    }

    void insert(long long i, long long j, long long v){
        insertx(i, j, v, 0, 0, sizex, 0, 0, sizey); // O(2*m*log(n)*log(m))
    }

    long long query(long long l, long long r, long long b, long long t){
        return queryx(l, r, b, t, 0, 0, sizex, 0, 0, sizey); // O(log(n)*log(m))
    }
};

// Just for referance
class FenwickTree{
public:
    vector<long long> bit;
    long long n;
    
    FenwickTree(long long size){
        n = size;
        bit.assign(n, 0LL);
    }   

    long long query(long long x){
        long long i = x, res = 0;
        auto g = [](long long x) -> long long { return (x & (x + 1));};
        while(i >= 0){
            res += bit[i];
            i = g(i) - 1; // g(x) = x & (x + 1)
        }
        return res;
        
    }

    long long query(long long l, long long r){
        r--; l--;
        return query(l) + query(r);
    }

    void inc(long long i, long long v){
        long long x = i;
        auto p = [](long long x) -> long long { return (x | (x + 1));};
        while(x < n){
            bit[x] += v;
            x = p(x); // p(x) = x | (x + 1)
        }
    }
};

class fenwicktree2d {
private:
    long long query(long long r, long long t){
        long long x = r, res = 0;
        while(x >= 0){
            long long y = t;
            while(y >= 0){
                res += bit[x][y];
                y = (y & (y + 1)) - 1;
            }
            x = (x & (x + 1)) - 1;
        }
        return res;
    }

public:
    vector<vector<long long>> bit;
    long long n, m;

    fenwicktree2d(long long r, long long c){
        n = r, m = c;
        bit.assign(n, vector<long long>(m, 0LL));   
    }

    void inc(long long i, long long j, long long v){
        long long x = i; 
        while(x < n){
            long long y = j;
            while(y < m){
                bit[x][y] += v;
                y = (y | (y + 1));
            }
            x = (x | (x + 1));
        }
    }

    // [l, r - 1][b, t - 1] or [l, r)[b, t)
    long long query(long long l, long long r, long long b, long long t){
        l--; r--; b--; t--;
        return query(r, t) - query(l, t) - query(r, b) + query(l, b);
    }
};

class sparsetable2d {
public:
    // INCOMPLETE
};

void solve(){
    // Question 01
    // [=]() -> void {
    //     long long n = uid(1, 10), m = uid(1, 10);
    // }();
    // Ends

    // 2D Segement Tree
    auto prog01 = [=]() -> void {
        // r[4][4]
        long long n = 4, m = 4;
        vector<vector<long long>> rect = {
            { 1, 2, 3, 4 },
            { 5, 6, 7, 8 },
            { 1, 7, 5, 9 },
            { 3, 0, 6, 2 },
        };
        dbg(rect);
        segtree2d st(n, m);
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < m; j++){
                // dbg(i); dbg(j); dbg(rect[i][j]);
                st.insert(i, j, rect[i][j]); 
                // dbgv('\n');
            }
        }
        dbg(st.query(2, 4, 2, 4));
        st.insert(3, 3, 10);
        dbg(st.query(2, 4, 1, 4));
    };
    prog01();
    // Ends

    // 2D Fenwick Tree
    auto prog02 = [=]() -> void {
        // r[4][4]
        long long n = 4, m = 4;
        vector<vector<long long>> rect = {
            { 1, 2, 3, 4 },
            { 5, 6, 7, 8 },
            { 1, 7, 5, 9 },
            { 3, 0, 6, 2 },
        };

        fenwicktree2d ft(n, m);
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < m; j++){
                ft.inc(i, j, rect[i][j]);
            }
        }
        dbg(ft.query(2, 4, 2, 4));
        ft.inc(3, 3, 10 - rect[3][3]);
        dbg(ft.query(2, 4, 1, 4));
    };
    prog02();
    // Ends

    // 2D Sparse table 
    auto prog03 = [=]() -> void {

    };
    // Ends
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