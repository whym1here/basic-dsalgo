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

// Class
class segtree {
private:
    // Functions
    void set(long long i, long long v, long long x, long long lx, long long rx){
        if(rx - lx == 1){
            tree[x] = v;
            return;
        }
        long long m = (lx + rx)/2;
        if(i < m){
            set(i, v, 2*x + 1, lx, m);
        } else {
            set(i, v, 2*x + 2, m, rx);
        }
        tree[x] = tree[2*x + 1] + tree[2*x + 2];
    }

    long long get(long long l, long long r, long long x, long long lx, long long rx){
        // This ensures that our get is always correct
        if(lazy[x] != 0){
            tree[x] += (rx - lx)*lazy[x];

            // Making children lazy
            propogate(x, lx, rx);
        }

        if(lx >= r or rx <= l){
            return 0; // NULL VALUE / NUTERAL VALUE
        }
        if(l <= lx and rx <= r){
            return tree[x];
        }
        long long m = (lx + rx)/2;
        long long s1 = get(l, r, 2*x + 1, lx, m);
        long long s2 = get(l, r, 2*x + 2, m, rx);
        return s1 + s2;
    }

    void op(long long l, long long r, long long v, long long x, long long lx, long long rx){
        // Check for laziness
        if(lazy[x] != 0){
            // Removed the laziness from this node
            tree[x] = (rx - lx)*lazy[x];
            
            // spread laziess to child nodes if it exists
            propogate(x, lx, rx);
        }

        // Useless case
        if(lx >= r or rx <= l){
            return;
        }

        if(l <= lx and rx <= r){
            tree[x] += (rx - lx)*v; 

            // Create then remove the laziness for this node
            lazy[x] += v;              
            
            // spread laziess to child nodes if it exists
            propogate(x, lx, rx);

            // This is what being lazy really means
            return; 
        }

        long long m = (lx + rx)/2;
        op(l, r, v, 2*x + 1, lx, m);
        op(l, r, v, 2*x + 2, m, rx);
        tree[x] = tree[2*x + 1] + tree[2*x + 2];
    }

    void propogate(long long x, long long lx, long long rx){
        if(rx - lx != 1){
            lazy[2*x + 1] += lazy[x];
            lazy[2*x + 2] += lazy[x];
        }
        lazy[x] = 0;
    }

public:
    // Data Members
    vector<long long> tree;
    vector<long long> lazy;
    long long size;

    // Functions
    segtree(long long n){
        size = 1;
        while(size < n) size *= 2;
        tree = vector<long long>(2*size, 0);
        lazy = vector<long long>(2*size, 0);
    }

    void set(long long i, long long v){
        set(i, v, 0, 0, size);
    }

    void op(long long l, long long r, long long v){
        op(l, r, v, 0, 0, size);
    }

    long long get(long long l, long long r){
        return get(l, r, 0, 0, size);
    }
};

class refsegtree {
public:
    long long size;
    vector<long long> a;

    refsegtree(long long n){
        size = n;
        a = vector<long long>(size, 0);
    }

    void set(long long i, long long v){
        a[i] = v;
    }

    void op(long long l, long long r, long long v){
        for(long long i = l; i < r; i++){
            a[i] += v;
        }
    }

    long long get(long long l, long long r){
        long long ans = 0;
        for(long long i = l; i < r; i++){
            ans += a[i];
        }
        return ans;
    }
    
};

// Functions


// Solution
void solve(){
    const long long n = 6;
    vector<long long> a = {
        1, 3, 5, 7, 9, 11
    };

    segtree st(n);
    refsegtree rst(n);

    for(long long i = 0; i < n; i++){
        st.set(i, a[i]);
        rst.set(i, a[i]);
    }

    dbg(rst.a);
    dbg(st.get(1, 4));
    dbg(rst.get(1, 4));


    cerr << nline;

    //  += 10 [1, 5]
    st.op(1, 6, 10);
    rst.op(1, 6, 10);

    dbg(rst.a);
    dbg(st.get(1, 4));
    dbg(rst.get(1, 4));

    cerr << nline;

    // += 2 [0, n-1]
    st.op(0, n, 2);
    rst.op(0, n, 2);

    dbg(rst.a);
    dbg(st.get(1, 4));
    dbg(rst.get(1, 4));

    cerr << nline;

    for(long long i = 0; i < n; i++){
        dbg(rst.a);
        dbg(st.get(i, i+1));
        dbg(rst.get(i, i+1));

        cerr << nline;
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