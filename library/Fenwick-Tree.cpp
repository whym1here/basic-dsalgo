#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BIT {
public:
    vector<T> bit;
    int n;

    BIT() {
        n = 0;
    }

    BIT(int _n) {
        n = _n;
        bit.assign(n, 0);
    }

    // increase the value of element at idx idxex i.e a[idx]
    void inc(int idx, T val) {
        assert(0 <= idx and idx < n);
        for(int i = idx + 1; i <= n; i += (i & -i))
            bit[i - 1] += val;
    }

    // sum of all the elements in [0..idx]
    T query(int idx) {
        assert(0 <= idx and idx < n);
        T res = 0;
        for(int i = idx + 1; i > 0; i -= (i & -i))
            res += bit[i - 1];
        return res;
    }

    // get the value of element at idx index i.e a[idx]
    T at(int idx) {
        assert(0 <= idx and idx < n);
        return query(idx) - (idx - 1 >= 0? query(idx - 1): 0);
    }

    // sum of all the element [l..r]
    T at(int l, int r) {
        assert(0 <= l and l <= r and r < n);
        return query(r) - (l - 1 >= 0? query(l - 1): 0);
    }

};

template<typename T>
class FT {
public:
    BIT<T> f1, f2;
    int n;

    FT() {
        n = 0;
    }

    FT(int _n) {
        n = _n;
        f1 = f2 = BIT<T>(_n + 1);
    }

    // increase the value of element at idx idxex i.e a[idx]
    void inc(int idx, T val){
        assert(0 <= idx and idx < n);
        inc(idx, idx, val);
    }

    // increase all the elements in [l..r] by val
    void inc(int l, int r, T val) {
        assert(0 <= l and l <= r and r < n);
        f1.inc(l, val); 
        f1.inc(r + 1, -val);
        f2.inc(l, val * (l - 1)); 
        f2.inc(r + 1, -val * r);
    }

    // sum of all the elements in [0..idx]
    T query(int idx) {
        assert(0 <= idx and idx < n);
        return f1.query(idx) * idx - f2.query(idx);
    }

    // get the value of element at idx index i.e a[idx]
    T at(int idx) {
        assert(0 <= idx and idx < n);
        return query(idx) - (idx - 1 >= 0? query(idx - 1): 0);
    }

    // sum of all the element [l..r]
    T at(int l, int r) {
        assert(0 <= l and l <= r and r < n);
        return query(r) - (l - 1 >= 0? query(l - 1): 0); 
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}