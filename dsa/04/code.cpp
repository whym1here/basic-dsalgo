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
void counting_sort(vector<ll> & arr, ll place){
    const ll n = arr.size();
    vector<ll> output(n, 0);
    vector<ll> count(10, 0);

    ll index = -1;

    for(ll i = 0; i < n; i++){
        index = arr[i]/place;
        count[index%10]++;
    }

    for(ll i = 1; i < 10; i++){
        count[i] += count[i-1];
    }

    ll i = n - 1;

    while (i >= 0){
        index = arr[i]/place;
        // index = count[index%10] - 1 ; but position = count[index%10] 
        output[count[index%10]-1] = arr[i];
        count[index%10]--;
        i -= 1;  
    }
    
    for(ll i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void my_counting_sort(vector<ll> & arr, ll place){
    // For length of arr
    ll const n = arr.size();
    ll const m = 10;
    
    // For count sort algo
    vector<ll> cnt(m, 0);
    vector<ll> sorted_arr(n , 0);

    for(ll i = 0; i < n ; i++){
        // counting based on 10^(place-1) bit for deciaml system
        cnt[(arr[i]/place)%10]++;
    }
    
    for(ll i = 1; i < m; i++){
        cnt[i] += cnt[i-1]; // to get the max postion of a count 
        // max index = postion - 1 || index = cnt[i] - 1
    }

    ll idx = -1;
    
    // dbg(cnt);
    // dbg("Loop");

    // As we sort from last so that we hold the previous state of partiacally sorted array
    for(ll i = n-1; i >= 0 ; i--){ 
        idx = (arr[i]/place)%10;
        sorted_arr[cnt[idx]-1] = arr[i];
        cnt[idx]--;
        // dbg(cnt);
    }

    for(ll i = 0; i < n ; i++){
        arr[i] = sorted_arr[i];
    }
}

void radix_sort(vector<ll> & arr){
    ll uplim = -1;
    for(auto i : arr){
        if (i > uplim) uplim = i;
    }
    
    ll place = 1;

    while(uplim/place > 0){
        counting_sort(arr, place);
        place *= 10;
    }
}

void my_radix_sort(vector<ll> & arr){
    ll uplim = -1;
    for(auto i : arr){
        if (i > uplim) uplim = i;
    }
    ll place = 1;
    while(uplim/place > 0){
        my_counting_sort(arr, place);
        place *= 10; // we are doing it for decimal system
    }
}

// Solution
void solve(){
    vector<ll> a = {44, 232, 3213, 21321, 31233, 323, 1, 3234, 1233, 90324, 4334, 423842, 9324221, 3443258, 99343824};
    vector<ll> b = {44, 232, 3213, 21321, 31233, 323, 1, 3234, 1233, 90324, 4334, 423842, 9324221, 3443258, 99343824};
    dbg(a);
    dbg(b);
    my_radix_sort(b);
    radix_sort(a);
    // dbg("OUTPUT");
    dbg(a);
    dbg(b);
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