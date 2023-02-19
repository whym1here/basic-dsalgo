#include <bits/stdc++.h>
using namespace std;

template<typename T>
class RMQ {
public:
    vector<vector<T>> st;
    function<T(T, T)> op;
    int n, m;

    RMQ(const vector<T>& a, function<T(T, T)> _op) {
        n = (int)a.size(); m = __lg(n) + 1; // ceil(log(r - l + 1))
        st = vector<vector<T>>(n, vector<T>(m));
        op = _op;
        int p = 1;
        for(int j = 0; j < m; j++) {
            for(int i = 0; i + p - 1 < n; i++) {
                if(j == 0) st[i][j] = a[i];
                else st[i][j] = op(st[i][j - 1], st[i + (p >> 1)][j - 1]);
            }
            p *= 2;
        }
    }

    T query(int l, int r) {
        int sz = __lg(r - l + 1); // floor(log(r - l + 1))
        return op(st[l][sz], st[r + 1 - (1 << sz)][sz]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    RMQ<int> rmq(a, [](int x, int y) -> int { return min(x, y); });
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << rmq.query(l, r) << '\n';
    }
    
    return 0;
}
