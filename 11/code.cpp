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

// Minimum number of step require convert A -> B   
long long levenshtein_distance(string A, string B){
    vector<vector<long long>> dp(A.length()+1, vector<long long>(B.length()+1, 0));
    for(long long i = 0; i < A.length()+1; i++){
        for(long long j = 0; j < B.length()+1; j++){
            if(i == 0 or j == 0){
                dp[i][j] = i+j;
                continue;
            }
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min({
                    dp[i-1][j-1], dp[i-1][j], dp[i][j-1]
                });
            }
        }
    }
    return dp[A.length()][B.length()];
}

// test alginment for printing
long long txt_align(const vector<long long> & w, long long L){
    const long long n = w.size();
    vector<long long> dp(n+1, 0);
    for(long long i = 1; i <= n; i++){
        dp[i] = 1e7+1;
        long long s = 0;
        for(long long k = 1; k <= i; k++){
            s += w[i-k];
            if(s > L){
                break;
            }
            dp[i] = min({
                dp[i], dp[i-k] + ((L-s)*(L-s)*(L-s))
            });
        }
    }
    dbg(dp);
    return dp[n];
}

// Solution
void solve(){
    dbg(levenshtein_distance(
        "apple", "alpine"
    ));
    dbg(levenshtein_distance(
        "document", "docament"
    ));

    dbg(txt_align(
        {1, 2, 4, 6, 7, 8, 7, 4, 3, 2, 1, 3, 6, 7, 7, 5, 5},
        10
    ));
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