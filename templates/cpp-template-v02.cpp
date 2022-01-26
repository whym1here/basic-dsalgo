#include <bits/stdc++.h>

// NAMESPACE
using namespace std;

// TYPEDEFS
typedef long long ll; 
typedef unsigned long long ull;
typedef long double lld;
typedef string str; // copied from Benq's code 

// MACROS
#define pr(x) cout<<(x)<<nline // From my python template
#define prl(x) cout<<(x)<<' ' // same as above
#define nline '\n' // Copied from a friend 
#define f first // But I never use pair
#define s second // Same as above
#define pb push_back
#define all(x) (x).begin(),(x).end() // Type less for sorting

// DEBUG FUNCTIONS (very advance)
template<typename T>long long SIZE(T (&t)){return t.size();}
template<typename T, size_t N>long long SIZE(T (&t)[N]){return N;}
string to_string(char t){return "'" + string({t}) + "'";}
string to_string(bool t){return t ? "true" : "false";}
string to_string(const string &t, long long x1=0, long long x2=1e9){string ret = "";for(long long i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ret += t[i];}return '"' + ret + '"';}
string to_string(const char* t){string ret(t);return to_string(ret);}
template<size_t N>string to_string(const bitset<N> &t, long long x1=0, long long x2=1e9){string ret = "";for(long long i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ret += t[i] + '0';}return to_string(ret);}
template<typename T, typename... Coords>string to_string(const T (&t), long long x1=0, long long x2=1e9, Coords... C);
template<typename T, typename S>string to_string(const pair<T, S> &t){return "(" + to_string(t.first) + ", " + to_string(t.second) + ")";}
template<typename T, typename... Coords>string to_string(const T (&t), long long x1, long long x2, Coords... C){string ret = "[";x1 = min(x1, SIZE(t));auto e = begin(t);advance(e,x1);for(long long i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ret += to_string(*e, C...) + (i != _i ? ", " : "");e = next(e);}return ret + "]";}
template<long long Index, typename... Ts>struct print_tuple{string operator() (const tuple<Ts...>& t) {string ret = print_tuple<Index - 1, Ts...>{}(t);ret += (Index ? ", " : "");return ret + to_string(get<Index>(t));}};
template<typename... Ts>struct print_tuple<0, Ts...> {string operator() (const tuple<Ts...>& t) {return to_string(get<0>(t));}};
template<typename... Ts>string to_string(const tuple<Ts...>& t) {const auto Size = tuple_size<tuple<Ts...>>::value;return print_tuple<Size - 1, Ts...>{}(t);}
void dbgr(){;}
template<typename Heads, typename... Tails>void dbgr(Heads H, Tails... T){cout << to_string(H) << " | ";dbgr(T...);}
void dbgs(){;}
template<typename Heads, typename... Tails>void dbgs(Heads H, Tails... T){cout << H << " ";dbgs(T...);}

// DEBUG
#ifndef ONLINE_JUDGE
#define dbgv(...) cerr << to_string(__VA_ARGS__) << endl;
#define dbg(...) cerr << "" << #__VA_ARGS__ << " = "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cerr << endl;
#define dbgm(...) cerr << "" << #__VA_ARGS__ << " = "; dbgr(__VA_ARGS__);
#else
#define dbgv(...)
#define dbg(...)
#define dbgr(...)
#define dbgm(...)
#endif

// CLASS (uncomment for use)
// class Name{
// public:
//     ll a;
//     str b;
//     Name(/* args */);
//     ~Name();
// };

// CONSTANTS (uncomment for use)
// const ll mod97 = 1e9+7; 
// const ll modg = 998244353;
// const int max_i = 2e5+5; 
// const ll inf_ll = 1e18; 
// const lld pi_lld = acos((lld)-1);

// Function (predefined)
ll binpow(ll a, ll b, ll m = (1e18)) {
    a %= m;
    ll res = 1;
    if(a == 0) return 0;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// Functions


// Solution
void solve(){
    
}   

// Main
int main(){
    // Fast IO
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 

    // For local code execution
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