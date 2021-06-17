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
void quick_sort(vector<ll> &a, ll l, ll r){
    if (r - l <= 1){
        return ;
    }

    // Random index from l to r-1
    ll range = r-1 - l + 1; // range = max - min +1
    ll idx = rand() % range +l; // value = rand() % range + min
    
    ll x = a[idx];
    ll m = l;

    for(ll i = l; i < r ; i++){
        if(a[i] < x){
            swap(a[i], a[m]);
            m++;
        }
    } 

    // Recursion
    quick_sort(a, l, m);
    quick_sort(a, m, r);
}

// Order Statistics : to find array[k] where k is given and an unsorted form of array is given
ll find_rnd(vector<ll> &a, ll l, ll r, ll k){
    if (r - l <= 1){
        return a[k];
    }

    // Random index from l to r-1
    ll range = r-1 - l + 1; // range = max - min +1
    ll idx = rand() % range +l; // value = rand() % range + min
    
    ll x = a[idx];
    ll m = l;

    for(ll i = l; i < r ; i++){
        if(a[i] < x){
            swap(a[i], a[m]);
            m++;
        }
    } 
    if (k < m) return find_rnd(a, l, m, k);
    else return find_rnd(a, m, r, k);
}

// Solution
void solve(){
    vector<ll> v1 = {7, 4, 3, 5, 1, 9, 2, 6, 8, 10};
    dbg(v1);
    quick_sort(v1, 0, v1.size());
    for(auto x : v1) prl(x);
    pr(' ');
    vector<ll> v2 = {7, 4, 3, 5, 1, 9, 2, 6, 8, 10};
    ll i = 7;
    prl("i =");pr(i);
    prl("find(i) =");
    pr( find_rnd(v2, 0, v2.size(), i) );
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