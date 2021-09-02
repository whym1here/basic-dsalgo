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

// Classes
class slowdsu{
    public:
    // p[i] refers to representative element of the set which i is part of
    static void join(ll x, ll y, vector<ll> & p){
        x = find(x, p), y = find(y, p);
        for(ll i = 0; i < p.size(); i++){ // O(n)
            if(p[i] == x){
                p[i] = y;
            }
        }
    }

    static ll find(ll x, vector<ll> & p){ // O(1)
        if(p.size() < x){
            cerr << "Error element not in array or vector" << endl;
            return LLONG_MIN;
        }
        else{
            return p[x];
        }
    }
};

class middsu{
public:
    // p[i] refers to representative element of the set which i is part of
    static void join(ll x, ll y, vector<ll> & p ,vector<vector<ll>> & lst){
        x = find(x, p), y = find(y, p);
        if(lst[x].size() > lst[y].size()){
            swap(x, y);
        }
        for(auto i : lst[x]){
            p[i] = y;
            lst[y].push_back(i);
        }
        lst[x].clear();
    }
    
    static ll find(ll x, vector<ll> & p){ // O(1)
        return slowdsu::find(x, p);
    }

};

class fastdsu{
public:
    // p[i] refers to parent of i in a tree 
    // Using Rank Heuristics
    static void join(ll x, ll y, vector<ll> & p, vector<ll> & r){
        // For each element x we find the longest path in the tree and
        // the length of the path is the rank of the element x stored in r
        x = find(x, p), y = find(y, p);
        if (r[x] > r[y]){
            swap(x, y);
        }
        p[x] = y;
        if(r[x] == r[y] and x != y){
            r[y]++;
        }
    }
    
    // Using Path Compression 
    static ll find(ll x, vector<ll> & p){ 
        // O(n) but Total is : alpha(n, m) 
        // n = size of tree
        // m = number of finds
        // alpha = inverse ackermann's function 
        // as n increases, alpha(n, m) increases but as m increases, alpha(n, m) decreases
        if(x > p.size()){
            cerr << "Error element not in array or vector" << endl;
            return LLONG_MIN;
        }
        ll y = x, z = 0;
        while(p[y] != y){
            y = p[y];
        }
        while(p[x] != x){
            z = p[x];
            p[x] = y;
            x = z;
        }
        return x;
    }

};

// Functions


// Solution
void solve(){
    cerr << "\t\t" << "SLOWDSU" << endl;
    vector<ll> p1(8);
    iota(p1.begin(), p1.end(), 0);
    dbg(p1);
    slowdsu::join(1, 2, p1);
    slowdsu::join(1, 5, p1);
    slowdsu::join(7, 4, p1);
    slowdsu::join(3, 6, p1);
    dbg(p1);
    cerr << "---------------------------------" << endl;

    cerr << "\t\t" << "MIDDSU" << endl;
    vector<ll> p2(8);
    iota(p2.begin(), p2.end(), 0);
    vector<vector<ll>> lst1(8);
    for(ll i = 0; i < lst1.size(); i++){
        lst1[i].push_back(i);
    }
    dbg(p2); dbg(lst1);
    middsu::join(1, 2, p2, lst1);
    middsu::join(1, 5, p2, lst1);
    middsu::join(7, 4, p2, lst1);
    middsu::join(3, 6, p2, lst1);
    dbg(p2); dbg(lst1);
    cerr << "---------------------------------" << endl;

    cerr << "\t\t" << "FASTDSU" << endl;
    vector<ll> p3(8);
    iota(p3.begin(), p3.end(), 0);
    vector<ll> r1(8, 1);
    fastdsu::join(1, 2, p3, r1);
    fastdsu::join(1, 5, p3, r1);
    fastdsu::join(7, 4, p3, r1);
    fastdsu::join(3, 6, p3, r1);
    dbg(p3); dbg(r1);
    cerr << "---------------------------------" << endl;
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