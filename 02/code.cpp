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
void insert_heap(vector<ll> &h, ll x){
    h.pb(x);
    ull n = h.size();
    ull i = n-1;
    while(i > 0 and h[i] < h[(i-1)/2]){
        swap(h[i], h[(i-1)/2]);
        i = (i-1)/2;
    }
}

ll remove_min(vector<ll> &h){
    ull n = h.size();
    ll last_element = h[0];
    
    swap(h[0], h[n-1]);
    h.resize(n-1);
    n = h.size();

    ull i = 0, j = 0;
    while (2*i+1 < n){
        j = 2*i+1;
        if((2*i+2 < n) and h[2*i+2] < h[j]){
            j = 2*i+2;
        }
        if(h[i] <= h[j]){
            break;
        }
        swap(h[i], h[j]);
        i = j;
    }
    return last_element;
}

void heap_sort(vector<ll> &a){
    vector<ll> temp;
    for(auto i : a){
        insert_heap(temp, i);
    }
    for(ll i = 0; i < a.size(); i++){
        a[i] = remove_min(temp);
    }
}

void shift_up(vector<ll> &h, ull idx){    
    while(idx > 0 and h[(idx-1)/2] > h[idx]){
        swap(h[(idx-1)/2], h[idx]);
        idx = (idx-1)/2;
    }
}

void shift_down(vector<ll> &h, ull idx){
    ull n = idx+1;
    ull i = 0, j = 0;
    while(2*i+1 < n){
        j = 2*i+1;
        if(2*i+2 < n and h[2*i+2] < h[j]){
            j = 2*i+2;
        }
        if(h[i] <= h[j]){
            break;
        }
        swap(h[i], h[j]);
        i = j;
    }
}

void memory_eff_heap_sort(vector<ll> &a){
    ull n = a.size();
    for(ll i = 0; i < n ; i++){
        shift_up(a, i);
    }

    for(ll i = n-1; i > 0; i--){
        swap(a[0], a[i]);
        shift_down(a, i-1);
    }

    reverse(a.begin(), a.end());
}


// Solution
void solve(){
    vector<ll> a, b = {26, 15, 2, 5, 8, 9, 7, 13, 15, 10};
    for(auto i : b){
        insert_heap(a, i);
        // dbg(a);
    }
    
    ll t = 10;
    while(t--){
        ll val = remove_min(a);
        pr(val);
        // dbg(a);
    }
    
    vector<ll> some = {11, 34, 66, 656, 453, 33, 66, 21, 1, 8, 7, 3 ,6};
    heap_sort(some);
    for(auto i : some){
        prl(i);
    }
    pr(' ');

    vector<ll> some1 = {11, 34, 66, 656, 453, 33, 66, 21, 1, 8, 7, 3 ,6};
    memory_eff_heap_sort(some1);
    for(auto i : some1){
        prl(i);
    }
    pr(' ');
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