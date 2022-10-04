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

// Structs (uncomment for use)
// typedef struct some_name{
//     ll a;
//     str b;
// }real_name_of_struct;

// Functions
ll basic_binary_search(vector<ll> & a, ll x){
    ll n = a.size(), l = 0, r = n-1, m = 0;
    while(r >= l){
        m = (l+r)/2;
        if(a[m] < x){
            l = m+1;
        }
        else if (a[m] > x){
            r = m-1;
        }
        else{
            return m;
        }
    }
    return -1;
}

ll left_greater_equal(vector<ll> & a, ll x){
    ll n = a.size(), l = -1, r = n, m = 0;
    while(r > l+1){
        m = (l+r)/2;
        if(a[m] >= x){
            r = m;
        }
        else{
            l = m;
        }
    }
    return r; // returns n if x > a[n-1] 
}


ll right_less_equal(vector<ll> & a, ll x){
    ll n = a.size(), l = -1, r = n, m = 0;
    while(r > l+1){
        m = (l+r)/2;
        if(a[m] <= x){
            l = m;
        }
        else{
            r = m;
        }
    }
    return l; // return -1 if x < a[0]
}

// Tips
// use l to get maximum for function good(...)
// use r for get minimum for function good(...)

// Solution
void solve(){
    vector<ll> a = {2, 5, 6, 10, 12, 18, 21};
   
    dbg(a);
    dbg(basic_binary_search(a, 2));
    dbg(basic_binary_search(a, 21));
    dbg(basic_binary_search(a, 12));
    dbg(basic_binary_search(a, 4));
    cerr<<"\n";

    dbg(a);
    dbg(left_greater_equal(a, 2));
    dbg(left_greater_equal(a, 21));
    dbg(left_greater_equal(a, 12));
    dbg(left_greater_equal(a, 4));
    dbg(left_greater_equal(a, 7));
    dbg(left_greater_equal(a, 15));
    dbg(left_greater_equal(a, 1));
    dbg(left_greater_equal(a, 50));
    cerr<<"\n";

    dbg(a); 
    dbg(right_less_equal(a, 2));
    dbg(right_less_equal(a, 21));
    dbg(right_less_equal(a, 12));
    dbg(right_less_equal(a, 4));
    dbg(right_less_equal(a, 7));
    dbg(right_less_equal(a, 15));
    dbg(right_less_equal(a, 1));
    dbg(right_less_equal(a, 50));
    cerr<<"\n";
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