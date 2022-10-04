#include <bits/stdc++.h>

// Debug
#ifndef ONLINE_JUDGE
#define dbg(x) cerr<<#x<<" = "; deb(x); cerr<<endl;
#else
#define dbg(x)
#endif

// Macros
#define pr(x) cout<<(x)<<nline // From my python template
#define prl(x) cout<<(x)<<' ' // same as above
#define nline '\n' // Copied from a friend 
#define f first // But I never use pair
#define s second // Same as above
#define pb push_back

// Namespace
using namespace std;

// Typrdefs
typedef long long ll; 
typedef unsigned long long ull;
typedef long double lld;
typedef string str; // copied from Benq's code 

// Debug Functions
template<typename T>void deb(T avar){cerr<<avar;}
template<typename T, typename V>void deb(pair<T,V> apair){cerr<<"(";deb(apair.f);cerr<<", ";deb(apair.s);cerr<<")";}
template<typename T>void deb(vector<T> avec){ cerr<<"[ ";for(const auto &i: avec){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T, typename V>void deb(map<T,V> amap){cerr<<"[ ";for(const auto &i: amap){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T, typename V>void deb(unordered_map<T,V> amap){cerr<<"[ ";for(const auto &i: amap){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T>void deb(set<T> aset){cerr<<"[ ";for(const auto &i: aset){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T>void deb(unordered_set<T> aset){cerr<<"[ ";for(const auto &i: aset){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T>void deb(multiset<T> aset){cerr<<"[ ";for(const auto &i: aset){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T>void deb(unordered_multiset<T> aset){cerr<<"[ ";for(const auto &i: aset){deb(i);cerr<<' ';}cerr<<"] ";}

// Constants (uncomment for use)
// const int MOD = 1e9+7; 
// const int MX = 2e5+5; 
// const ll INF = 1e18; 
// const lld PI = acos((lld)-1);

// Random Numbers
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<long long>(a, b)(rng)

// Functions
long long binpow(long long a, long long b, long long m = (1e18)) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// Class 
class FenwickTree {
    // Inverse must exist for the operation
private:
    long long query(long long r){
        long long x = r;
        long long res = 0;
        while(x >= 0){
            res += bit[x];
            x = (x & (x + 1)) - 1;  // p[x] - 1, [ p(x) = (x) & (x + 1) ]
        }
        return res;
    }
public:
    vector<long long> bit;
    long long n;

    FenwickTree(long long sz){
        n = sz;
        bit = vector<long long>(n, 0);
    }

    // [l, r - 1]
    long long query(long long l, long long r){
        return query(r-1) - query(l-1);
    }

    void inc(long long i, long long v){
        long long j = i;
        while(j < n){
            bit[j] += v;
            j = j | (j + 1);
        }
    }
};

class reftree {
public:
    vector<long long> a;
    long long n;

    reftree(long long sz){
        n = sz;
        a = vector<long long>(n, 0);
    }

    long long query(long long l, long long r){
        if(l >= 0){
            long long res = 0;
            for(long long i = l ; i < r; i++){
                res += a[i];
            }
            return res;
        } else {
            long long res = 0;
            for(long long i = 0; i < r; i++){
                res += a[i];
            }
            return res;
        }
        
    }

    void inc(long long i, long long v){
        a[i] += v;
    }
};

class SparseTable {
    // Gives an error when l == r
public:
    vector<vector<long long>> m;
    long long n;

    SparseTable(vector<long long> & a, long long sz){
        n = sz;
        m = vector<vector<long long>>(n, vector<long long>((long long)log2(n) + 1, 0));
        for(long long i = 0; i < n; i++){
            m[i][0] = a[i];
        }

        for(long long j = 1; j <= (long long)log2(n); j++){
            for(long long i = 0; i <= n - binpow(2, j); i++){
                m[i][j] = min({
                    m[i][j-1], m[i + binpow(2, j-1)][j - 1]
                });
            }
        }
    }

    // [l, r-1]
    long long query(long long l, long long r){
        long long len = r - l;
        long long k = (long long)log2(len);
        return min({m[l][k], m[r - binpow(2, k)][k]});
    }
};

class reftable{
public:
    vector<long long> m;
    long long n;

    reftable(const vector<long long> & a, long long sz){
        n = sz;
        m = vector<long long>(a.begin(), a.end());
    }

    long long query(long long l, long long r){
        long long mn = (1e18);
        for(long long i = l; i < r; i++){
            mn = min({mn, m[i]});
        }
        return mn;
    }
};

// Solution
void solve(){
    const long long n = 100;
    const long long m = 50;

    FenwickTree ftree(n);
    reftree rtree(n);

    vector<long long> a(n);
    vector<pair<long long, long long>> b(m);
    
    for(long long i = 0; i < n; i++){
        a[i] = uid(0, 1000);
    }

    for(long long i = 0; i < m; i++){
        long long l = uid(0, n + 1), r = uid(0, n + 1);
        if(l > r) swap(l, r);
        b[i] = {l, r};
    }

    dbg(a);

    for(long long i = 0; i < n; i++){
        ftree.inc(i, a[i]);
        rtree.inc(i, a[i]);
    }
    // dbg(rtree.a);

    for(const auto & [x, y] : b){
        auto q = make_pair(x, y);
        dbg(q);

        dbg(ftree.query(x, y));
        dbg(rtree.query(x, y));
        if(ftree.query(x, y) != rtree.query(x, y)){
            cout << "ERROR with Fenwick Tree\n";
        }
        dbg(' ');
    }

    SparseTable spt(a, a.size());
    reftable rta(a, a.size());
    
    for(const auto & [x, y] : b){
        auto q = make_pair(x, y);
        dbg(q);

        dbg(spt.query(x, y));
        dbg(rta.query(x, y));
        if(spt.query(x, y) != rta.query(x, y)){
            cout << "ERROR with Sparse Table\n";
            cout << q.first << " " << q.second << "\n";
        }
        dbg(' ');
    }
}

// Main
int main(){
    // Fast IO
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 

    // For local code 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE    

    // Complete Solution
    ll T;cin>>T;while(T--)
    solve();
    return 0;
}

// Read this if you ever get stuck 
// Benq's advice : stuff you should look for
// 	* int overflow, array bounds
// 	* special cases (n=1?)
// 	* do smth instead of nothing and stay organized
// 	* WRITE STUFF DOWN
// 	* DON'T GET STUCK ON ONE APPROACH