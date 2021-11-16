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
const ll INF = 1e18; 
// const lld PI = acos((lld)-1);

// Class
namespace ques01 {
    class segtree {
    private:
        // Data Members
        long long size;
        vector<long long> tree;

        // Encapaclation
        void build(const vector<long long> & a, long long x, long long lx, long long rx){
            if(rx - lx == 1){
                if(lx < (long long)a.size()){
                    tree[x] = a[lx];
                }
                return;
            }
            long long m = (lx + rx)/2;
            build(a, 2*x+1, lx, m);
            build(a, 2*x+2, m, rx);
            tree[x] = tree[2*x+1] + tree[2*x+2];
        }

        void set(long long i, long long v, long long x, long long lx, long long rx){
            if(rx - lx == 1){
                tree[x] = v;
                return;
            }
            long long m = (lx + rx)/2;
            if(i < m){
                set(i, v, 2*x+1, lx, m);
            } else {
                set(i, v, 2*x+2, m, rx);
            }

            tree[x] = tree[2*x+1] + tree[2*x+2];
        }

        long long op(long long l, long long r, long long x, long long lx, long long rx){
            if(l >= rx or r <= lx){
                return 0;
            }
            if(l <= lx and rx <= r){
                return tree[x];
            }
            long long m = (lx + rx)/2;
            long long s1 = op(l, r, 2*x+1, lx, m);
            long long s2 = op(l, r, 2*x+2, m, rx);
            return s1 + s2;
        }

    public:
        // Functions
        void init(long long n){
            size = 1;
            while(size < n) size *= 2;
            tree.assign(2*size, 0LL);
        }

        void build(const vector<long long> & a){
            build(a, 0, 0, size);
        }

        void set(long long i, long long v){
            set(i, v, 0, 0, size);
        }

        long long op(long long l, long long r){
            return op(l, r, 0, 0, size);
        }
    };
};

namespace ques02 {
    class segtree {
    private:
        // Data Members
        long long size;
        vector<long long> tree;
    
        // Encapaclation
        void set(long long i, long long v, long long x, long long lx, long long rx){
            if(rx - lx == 1){
                tree[x] = v;
                return;
            }
            long long m = (lx + rx)/2;
            if(i < m){
                set(i, v, 2*x+1, lx, m);
            } else {
                set(i, v, 2*x+2, m, rx);
            }
    
            tree[x] = min(tree[2*x+1], tree[2*x+2]);
        }
    
        long long op(long long l, long long r, long long x, long long lx, long long rx){
            if(l >= rx or r <= lx){
                return INF;
            }
            if(l <= lx and rx <= r){
                return tree[x];
            }
            long long m = (lx + rx)/2;
            long long s1 = op(l, r, 2*x+1, lx, m);
            long long s2 = op(l, r, 2*x+2, m, rx);
            return min(s1, s2);
        }
    
    public:
        // Functions
        void init(long long n){
            size = 1;
            while(size < n) size *= 2;
            tree.assign(2*size, INF);
        }
    
        void set(long long i, long long v){
            set(i, v, 0, 0, size);
        }
    
        long long op(long long l, long long r){
            return op(l, r, 0, 0, size);
        }
    };
}

// Functions


// Solution
void solve1(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    // Complete Segment tree (implemented using RAM model)
    ques01::segtree st; st.init(n); st.build(a);

    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll i, v; cin >> i >> v;
            st.set(i, v);
        } else {
            ll l, r; cin >> l >> r;
            cout << st.op(l, r) << "\n";
        }
    }
}

void solve2(){
    ll n, m; cin >> n >> m;
    ques02::segtree st;st.init(n);
    for(ll i = 0; i < n; i++){
        ll v; cin >> v;
        st.set(i, v);
    }
 
    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll i, v; cin >> i >> v;
            st.set(i, v); // O(log(n))
        } else {
            ll l, r; cin >> l >> r;
            cout << st.op(l, r) << "\n"; // O(log(n))
        }
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
    // ll T;cin>>T;while(T--)
    solve1();
    solve2();
    return 0;
}

// Read this if you ever get stuck 
// Benq's advice : stuff you should look for
// 	* int overflow, array bounds
// 	* special cases (n=1?)
// 	* do smth instead of nothing and stay organized
// 	* WRITE STUFF DOWN
// 	* DON'T GET STUCK ON ONE APPROACH