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
const ll inf_ll = 1e17; 
// const int MX = 2e5+5; 
// const ll INF = 1e18; 
// const lld PI = acos((lld)-1);

// Structs (uncomment for use)
// typedef struct some_name{
//     ll a;
//     str b;
// }real_name_of_struct;

// Functions

// <= 
namespace helper{
    long long binary_search(const vector<pair<long long, long long>> & vp, const long long & val){
        long long l = -1, r = vp.size();
        long long m;
        while(r>l+1){
            m = (r+l)/2;
            if(vp[m].first <= val){
                l = m;
            }
            else{
                r = m;
            }
        }
        return l; // -1 for not valid
    }
}


namespace ques01{
    // 0-1 Knapsack Problem 
    // but costs[i] == wt[i] i = 0..n-1
    // so we need to maximize summation w[i] i = 0..n-1
    // S is the size of the bag 
    // i = number of weights under consideration 
    // j = capcity of bag
    // dp[i, j] = is it possible to have j with i items in considerartion
    // dp[i, j] = dp[i-1, j] | dp[i-1, j-wt[i-1]]
    // dp[0, 0] = true
    // dp[0, :] = false
    // dp[:, 0] = true
    long long knapsack(const vector<long long> & wt, const long long & S){
        const long long n = wt.size();
        vector<vector<bool>> dp(n+1, vector<bool>(S+1));
        for(long long i = 0; i < n+1; i++){
            for(long long j = 0; j < S+1; j++){
                if(j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0){
                    dp[i][j] = false;
                }
                else if(j >= wt[i-1]){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-wt[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // cerr << nline;
        // for(auto & i : dp){
        //     dbg(i);
        // }

        for(long long i = S; i >= 0; i--){
            if(dp[n][i]){
                return i;
            }
        }
        return 0;
    } // O(n.S)
    
}

namespace ques02{
    // 0-1 Knapsack Problem
    // 
    // i = [0..i-1] subset items in consideration 
    // j = capcity of the bag
    // dp[i, j] = max Σ c_i for subset [0..i-1] with Σ w_i <= j
    // 
    // Cases :
    // if j >= wt[i-1]
    // dp[i, j] = max(dp[i-1, j], cost[i-1]+dp[i-1, j-wt[i-1]])
    // else 
    // dp[i, j] = dp[i-1, j]
    // 
    // Base Case :
    // dp[0, 0] = 0
    // dp[0, :] = -inf or 0 depending on taste 
    // dp[:, 0] = 0
    long long knapsack(const vector<long long> & wt, const vector<long long> & cost, const long long & S){
        const long long n = wt.size();
        vector<vector<long long>> dp(n+1, vector<long long>(S+1));
        for(long long i = 0; i < n+1; i++){
            for(long long j = 0; j < S+1; j++){
                if(j == 0){
                    dp[i][j] = 0; 
                }
                else if(i == 0){
                    // if 0 is replaced by -inf then we get the dp for exact sum
                    // i.e. Σ w_i = j for some i belongs to {0..n-1}
                    dp[i][j] = 0; 
                }
                else if(j >= wt[i-1]){
                    dp[i][j] = max({
                        dp[i-1][j], cost[i-1]+dp[i-1][j-wt[i-1]]
                    });
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // cerr << nline;
        // for(auto & i : dp){
        //     dbg(i);
        // }
        return dp[n][S];
    } // O(n.S)
}



namespace ques03{
    // Operations : 
    // x = {i}  : x = 1 << i
    // x ∪ y    : x | y
    // x ∩ y    : x & y
    // x \ y    : x & (~y) [if y ⊂ x then (x - y) or (x ^ y ) ]
    // i ∈ x    : x & (1 << i) > 0 or (x >> i) & 1 > 0
    // 
    // 0-1 Knapsack Problem
    // here we are checking all the possibilities
    // Lets say we have 3 items
    // possiblities are :
    // [000, 001, 010, 011, 100, 101, 110, 111]
    // (1<<n) does this and 0 indexing helps here
    // as n = 3
    // we go from 0(000) to 2^3-1(111) 
    long long slow_knapsack(const vector<long long> & wt, const vector<long long> & cost, const long long & S){
        const long long n = wt.size();
        long long len = (1<<n), res = 0;
        for(long long x = 0; x < len ; x++){
            long long sw = 0;
            long long sc = 0;
            for(long long i = 0; i < n; i++){
                if(x&(1<<i)){
                    sc += cost[i];
                    sw += wt[i];
                }
            }
            if(sw <= S){
                res = max(res, sc);
            }
        }
        return res;
    } // O((2^n).n)

    // we want to optimize the above solution
    // we want to optimize 2^n part
    // spilt in the middle technique
    //  0 0 0 0 0 0 0 0 0 0 0 0 0 0 
    //  |----n/2----| |----n/2----|
    long long fast_knapsack(const vector<long long> & wt, const vector<long long> & cost, const long long & S){
        const long long n = wt.size();
        long long len = (1<<(n/2)), res = 0;
        vector<pair<long long, long long>> y_data; // f = wt, s = cost
        for(long long y = len; y < (1<<(n)); y++){
            long long sw = 0;
            long long sc = 0;
            for(long long i = n/2; i < n; i++){
                if(y&(1<<i)){
                    sc += cost[i];
                    sw += wt[i];
                }
            }
            y_data.push_back({sw, sc});
        }        
        sort(y_data.begin(), y_data.end());
        // dbg(y_data);
        for(long long x = 0; x < len; x++){
            // Find the value of y
            // w_2[y] <= S - w_1[x]
            // max C_1[y]
            long long sw = 0;
            long long sc = 0;
            for(long long i = 0; i < n/2; i++){
                if(x&(1<<i)){
                    sc += cost[i];
                    sw += wt[i];
                }
            }
            long long idx = helper::binary_search(y_data, (S-sw));
            // dbg(y_data);
            if(idx != -1){
                if(idx == y_data.size()) idx = y_data.size() -1; 
                // dbg(idx);
                // dbg(sc);
                // dbg(y_data[idx].second);
                // dbg(sc + y_data[idx].second);
                res = max(res, sc + y_data[idx].second);
            }
        }
        return res;
    } // O((2^(n/2)).n)

    // This is more memory efficient and faster 
    long long faster_knapsack(const vector<long long> & wt, const vector<long long> & cost, const long long & S){
        const long long n = wt.size();
        long long len = (1<<(n/2)), res = 0;
        vector<pair<long long, long long>> y_data; // f = wt, s = cost
        for(long long y = 0; y < (1<<(n-(n/2))); y++){
            long long sw = 0;
            long long sc = 0;
            for(long long i = 0; i < n - (n/2); i++){
                if(y&(1<<i)){
                    sc += cost[i+(n/2)];
                    sw += wt[i+(n/2)];
                }
            }
            y_data.push_back({sw, sc});
        }        
        sort(y_data.begin(), y_data.end());
        // dbg(y_data);
        for(long long x = 0; x < len; x++){
            // Find the value of y
            // w_2[y] <= S - w_1[x]
            // max C_1[y]
            long long sw = 0;
            long long sc = 0;
            for(long long i = 0; i < n/2; i++){
                if(x&(1<<i)){
                    sc += cost[i];
                    sw += wt[i];
                }
            }
            long long idx = helper::binary_search(y_data, (S-sw));
            // dbg(y_data);
            if(idx != -1){
                if(idx == y_data.size()) idx = y_data.size() -1; 
                // dbg(idx);
                // dbg(sc);
                // dbg(y_data[idx].second);
                // dbg(sc + y_data[idx].second);
                res = max(res, sc + y_data[idx].second);
            }
        }
        return res;
    } // O((2^(n/2)).n)
}

namespace ques04{
    // Subset sum
    // 
    // dp[i, j] = subset [0..i-1] under consideration and if Σ w_i = j for some i in subset    // 
    // dp[0, 0] = true 
    // dp[i, 0] = true i = 1...n
    // dp[0, j] = false j = 1...S
    // 
    // CASES :
    // if j - aset[i-1] >= 0
    // dp[i, j] = (dp[i-1, j] or dp[i-1, j - aset[i-1]])
    // else 
    // dp[i, j] = dp[i-1, j]
    bool subset_sum(const vector<long long> & aset, const long long & S){
        const long long n = aset.size();
        vector<vector<long long>> dp(n+1, vector<long long>(S+1));
        for(long long i = 0; i < n+1; i++){
            for(long long j = 0; j < S+1; j++){
                if(j == 0){
                    dp[i][j] = true;
                }
                else if (i == 0){
                    dp[i][j] = false;
                }
                else if(j >= aset[i-1]){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-aset[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][S];
    }
}

namespace ques05{
    // Number of knapsack 
    // 
    // INCOMPLETE
}

// Solution
void solve(){

    // Ques 01 :

    dbg(ques01::knapsack(
        {5, 3, 2, 3}, 9
    ));

    cerr << nline;

    // Ques 02 : 

    dbg(ques02::knapsack(
        {5, 3, 2, 3},
        {3, 2, 5, 3},
        9
    ));

    dbg(ques02::knapsack(
        {10, 20, 30},
        {60, 100, 120},
        50
    )); // ans = 220


    dbg(ques02::knapsack(
        {23, 31, 29, 44, 53, 38, 63, 85, 89, 82},
        {92, 57, 49, 68, 60, 43, 67, 84, 87, 72},
        165
    )); // ans = 309

    dbg(ques02::knapsack(
        {4, 5, 6},
        {1, 2, 3},
        3
    )); // ans = 0

    dbg(ques02::knapsack(
        {4, 5, 1},
        {1, 2, 3},
        4
    )); // ans = 3

    dbg(ques02::knapsack(
        {41, 50, 49, 59, 55, 57, 60},
        {442, 525, 511, 593, 546, 564, 617},
        170
    )); // ans = 1735

    cerr << nline;

    // Ques 03 : (slow) 

    dbg(ques03::slow_knapsack(
        {10, 20, 30},
        {60, 100, 120},
        50
    ));

    dbg(ques03::slow_knapsack(
        {23, 31, 29, 44, 53, 38, 63, 85, 89, 82},
        {92, 57, 49, 68, 60, 43, 67, 84, 87, 72},
        165
    )); // ans = 309

    dbg(ques03::slow_knapsack(
        {4, 5, 6},
        {1, 2, 3},
        3
    )); // ans = 0

    dbg(ques03::slow_knapsack(
        {4, 5, 1},
        {1, 2, 3},
        4
    )); // ans = 3

    dbg(ques03::slow_knapsack(
        {41, 50, 49, 59, 55, 57, 60},
        {442, 525, 511, 593, 546, 564, 617},
        170
    )); // ans = 1735
    
    cerr << nline;

    // Ques 03 : (fast)

    dbg(ques03::fast_knapsack(
        {10, 20, 30},
        {60, 100, 120},
        50
    )); // ans = 220


    dbg(ques03::fast_knapsack(
        {23, 31, 29, 44, 53, 38, 63, 85, 89, 82},
        {92, 57, 49, 68, 60, 43, 67, 84, 87, 72},
        165
    )); // ans = 309

    dbg(ques03::fast_knapsack(
        {4, 5, 6},
        {1, 2, 3},
        3
    )); // ans = 0

    dbg(ques03::fast_knapsack(
        {4, 5, 1},
        {1, 2, 3},
        4
    )); // ans = 3

    dbg(ques03::fast_knapsack(
        {41, 50, 49, 59, 55, 57, 60},
        {442, 525, 511, 593, 546, 564, 617},
        170
    )); // ans = 1735

    cerr << nline;

    // Ques 03 : (faster)

    dbg(ques03::faster_knapsack(
        {10, 20, 30},
        {60, 100, 120},
        50
    )); // ans = 220

    dbg(ques03::faster_knapsack(
        {23, 31, 29, 44, 53, 38, 63, 85, 89, 82},
        {92, 57, 49, 68, 60, 43, 67, 84, 87, 72},
        165
    )); // ans = 309

    dbg(ques03::faster_knapsack(
        {4, 5, 6},
        {1, 2, 3},
        3
    )); // ans = 0

    dbg(ques03::faster_knapsack(
        {4, 5, 1},
        {1, 2, 3},
        4
    )); // ans = 3

    dbg(ques03::faster_knapsack(
        {41, 50, 49, 59, 55, 57, 60},
        {442, 525, 511, 593, 546, 564, 617},
        170
    )); // ans = 1735

    cerr << nline;

    // Ques 04 :

    dbg(ques04::subset_sum(
        {3, 34, 4, 12, 5, 2}, 9
    ));

    dbg(ques04::subset_sum(
        {3, 34, 4, 12, 5, 2}, 30
    ));

    dbg(ques04::subset_sum(
        {1, 5, 3, 7, 4}, 12
    ));

    cerr << nline;
    
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