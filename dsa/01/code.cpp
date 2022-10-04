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
template<typename T>
void insertion_sort(T arr[], ull n){
    for(ull i = 0 ; i < n ; i++){
        ull j = i;
        while (j > 0 and arr[j] < arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

vector<ll> merge_sub(vector<ll> a, vector<ll> b){
    ull n = a.size();
    ull m = b.size();
    ull i = 0, j = 0, k = 0;
    vector<ll> c(n+m);
    while(i < n or j < m){
        if(j == m or (i < n and a[i] < b[j])){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }
    return c;
}

vector<ll> merge_sort(vector<ll> a){
    ull n = a.size();
    if(n < 2){
        return a;
    }
    vector<ll> b(n/2), c(n - (n/2));
    for(ull i = 0; i < n ; i++){
        if(i < n/2){
            b[i] = a[i];
        }
        else{
            c[i-(n/2)] = a[i];
        }
    }
    return merge_sub(merge_sort(b), merge_sort(c));
}

// Solution
void solve(){
    const ull n = 10;
    ll arr[n] = {5, 6, 7, 2, 1, 3, 9, 0, 4, 8};
    insertion_sort(arr, n);
    for(ull i = 0; i < n ; i++){
        prl(arr[i]);
    }
    pr(' ');

    vector<ll> a = {5, 6, 7, 2, 1, 3, 99, 5, 9, 11,0, 4, 8};
    a = merge_sort(a);
    for(auto i : a){
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