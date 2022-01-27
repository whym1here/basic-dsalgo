#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#else
#define dbgv(...)
#define dbg(...)
#define dbgr(...)
#define dbgm(...)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define pr(x) cout << (x) << '\n'
#define prl(x) cout << (x) << ' '
#define f first
#define s second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const long long mod97 = 1e9+7;
const long long INF = (1e18);
// const long long modg = 998244353;
// const int max_i = 2e5+5;
// const long double pi = acos((lld)-1);

long long binpow(long long a, long long b, long long m = INF) {
    a %= m;
    long long res = 1;
    if(a == 0) return 0;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    long long T = 1;
    cin >> T; 
    for(long long tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}