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

namespace naive{
    // Very slow and mutiple evalution of one result is done
    unsigned long long fabonacci(unsigned long long n){
        if(n < 3){
            return 1;
        }
        else{
            return fabonacci(n-1)+fabonacci(n-2);
        }

    }
}

namespace fast{
    // O(n) good implementation but can be done faster using Liner Algebra
    // This technique is called Memorization
    unsigned long long fabonacci(unsigned long long n){
        vector<long long> res(n+1, 0);
        if(n > 0) res[1] = 1;
        if(n > 1) res[2] = 1;
        for(size_t i = 3; i <= n; i++){
            res[i] = res[i-1]+res[i-2];
        }
        return res[n];

    }
}

namespace ques01{
    // Ques 01:
    // Here our current state is denoted only by n.
    // one dimentional dp 
    // 
    // Lets jump to some arbitrary state k. 
    // For this state we can say, 
    // dp[k] = dp[k-1] + dp[k-2]
    // as grasshoper can jump from k-1 or k-2 
    // if we know no of ways to reach k-1 and k-2 we can find no. ways to reach k
    // 
    // for this we need the intial condition for 0 and 1 
    // as dp[2] = dp[1] + dp[0]
    // 
    // form question we can say,
    // if 1 element exist then there is only one way
    // dp[0] = 1
    // if two element exit then reach 1 has only one way from 0 -> 1
    // dp[1] = 1
    // 
    // element :    0  1  2  3  4  5  6  7  8
    // no of ways : 1  1  2  3  5  8 13 21 34
    long long sol(long long n){
        if(n < 2) return 1;

        // Dynamic Programming
        vector<long long> dp(n+1);

        // Base Case
        dp[0] = 1, dp[1] = 1;
        
        for(size_t i = 2; i < n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }// O(n)
}

namespace ques02{
    // Ques 02 :
    // Here our state of dp can be represented by n only only number
    // n = the number of elements in array
    // dp[n] = numeber of such possible arrays
    // 
    // Let jump to a array of size k
    // dp[k] = number of array of size k
    // There are two possibilities :
    // Case 1 : Last element is 1
    // [ _ _ _ _ _ _ _ _ _ _ 1]
    // then 2nd last element must be 0 as no 2 ones allowed  
    // [ _ _ _ _ _ _ _ _ _ 0 1]
    // (k - 2) -> dp[k-2]
    // Case 2 : Last element is 0
    // [ _ _ _ _ _ _ _ _ _ _ 0]
    // (k - 1) -> dp[k-1]
    // 
    // dp[k] = case01 or case02
    // dp[k] = dp[k-1] + dp[k-2]
    long long sol(long long n){
        // number of way of not existing is 1
        if(n == 0) return 1; 
        // arrays : [0] [1]
        else if(n == 1) return 2;

        // Dyanmic Programming
        vector<long long> dp(n+1, 0);

        // Base Case
        dp[0] = 1, dp[1] = 2;
        
        for(size_t i = 2; i < n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }// O(n)
    // we can see ans for dp[2] = 3
    // arrays : [0, 0] ; [0, 1] ; [1, 0]
    // which can be verfied
}   

namespace ques03{
    // Ques 03 :
    // 
    // It is similar to question no 1
    // dp[n] = number of ways to reach n th cell
    // In this question we can 
    // if we loop at a state k
    // dp[k] = dp[k-1] + dp[k-2] + dp[k-3]
    long long sol(long long n){
        // dp[0] = 1
        if(n == 0) return 1;
        // 0 -> 1
        else if(n == 1) return 1;
        // 0 -> 1 -> 2 ; 0 -> 2
        else if(n == 2) return 2;

        // Dynamic Programming
        vector<long long> dp(n+1, 0);

        // Base Case
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        
        for(size_t i = 3; i < n+1; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }// O(n)
}

namespace ques04{
    // Ques 04 :
    // n = number of elements in a array 
    // dp[n] = number of ways to reach n th cell given the constraints
    // Here n is enough to represent our state
    //  
    // Let take a look at a state n
    // dp[n] = dp[n-1] or dp[n-2] or dp[n-3] or ... or dp[n-k]
    // dp[n] = dp[n-1] + dp[n-2] + ... + dp[n-k]

    long long slow_sol(long long n, long long k){
        // number of way of not existing is one
        vector<long long> dp(n+1, 0);

        // Base Case
        dp[0] = 1;
        
        for(long long i = 1; i < n+1; i++){
            for(long long j = 1; j <= k; j++){
                if(i-j >= 0){
                    dp[i] += dp[i-j];
                }
                else break;
            }
        }
        return dp[n];
    }// O(n.k)
    
    // Presum also know as cumulative sum 
    // It can be use here as a sliding window to only get the sum we want
    // It stores all the sum to that point
    // We can subtract what part we dont want 
    // [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ]
    //      |--------------|           sum needed 
    //         |--------------|        sum needed
    long long fast_sol(long long n, long long k){
        vector<long long> dp(n+1, 0), presum(n+1, 0);

        // Base Case
        dp[0] = 1, presum[0] = dp[0];
        
        for(long long i = 1; i < n+1; i++){
            if(i-k-1 < 0){
                dp[i] = presum[i-1];
                presum[i] = presum[i-1] + dp[i];
            }
            else{
                dp[i] = presum[i-1] - presum[i-k-1];
                presum[i] = presum[i-1] + dp[i]; 
            }
        }
        return dp[n];
    }// O(n)
}

namespace ques05{
    // Ques 05 :
    // n = current cell on which grasshoper is on
    // Single dimenational dp 
    // dp[n] = represent the minimum cost to reach nth cell
    // 
    // Lets say we are on a cell n i.e state n,
    // dp[n] = min(dp[n-1], dp[n-2]) + c[n]
    // 
    // Lets look at state 0 :
    // dp[0] = c[0] cause we have to start some were
    // 
    // Lets loot at state 1 :
    // dp[1] = dp[0] + c[1]
    long long sol(const vector<long long> & costs){
        const long long n = costs.size();
        if(n == 1) return costs[0];
        else if(n == 2) return costs[1]+costs[0];

        vector<long long> dp(n, 0);
        
        // Base Case
        dp[0] = costs[0], dp[1] = costs[1] + dp[0];
        
        for(long long i = 2; i < n ; i++){
            dp[i] = min(dp[i-1], dp[i-2]) + costs[i];
        }

        return dp[n-1];
    } // O(n)
}

namespace ques06{
    // Ques 06 :
    // 
    // Same as Ques 05
    // 
    // Lest jump to a state n
    // dp[n] = +inf
    // for i = 1...k:
    //     dp[n] = min(dp[n], dp[n-i]) + costs[n]
    long long slow_sol(const vector<long long> & costs, long long k){
        const long long n = costs.size();
        vector<long long> dp(n, 0);
        
        // Base Case
        dp[0] = costs[0];

        for(long long i = 1; i < n; i++){
            dp[i] = LLONG_MAX;
            for(long long j = 1; j <= k; j++){
                if(i-j >= 0){
                    dp[i] = min({dp[i], dp[i-j]}) + costs[i];
                }                
            }
        }
        return dp[n-1];
    } // O(n.k)

    // Stack and Queue
    // INCOMPLETE
    long long fast_sol(const vector<long long> & costs, long long k){
        const long long n = costs.size();
        vector<long long> dp(n, 0);
        dp[0] = costs[0];

        return 0;
    }
}

namespace ques07{
    // Ques 07 :
    // Same as before we just need to store the path
    // It can achieved using a vector
    pair<long long,vector<long long>> sol(const vector<long long> & costs, long long k){
        const long long n = costs.size();
        vector<long long> dp(n, 0);
        vector<long long> p(n, 0);

        // Base Case
        dp[0] = costs[0];
        p[0] = -1;

        for(long long i = 1; i < n; i++){
            dp[i] = LLONG_MAX;
            for(long long j = 1; j <= k; j++){
                if(i-j >= 0){
                    if(dp[i] > dp[i-j] + costs[i]){
                        dp[i] = dp[i-j] + costs[i];
                        p[i] = i-j; 
                    }
                }                
            }
        }

        // Path
        vector<long long> path;
        long long x = n-1;
        while(x != -1){
            path.push_back(x);
            x = p[x];
        }   
        reverse(path.begin(), path.end());
        return {dp[n-1], path};
    }
}

namespace ques08{
    // Ques 08 :
    // Let i and j describe the state of dp
    // i = current row 
    // j = current column
    // dp[i, j] = max cost to reach cell (i, j)
    // 
    // Lets move to some state (i, j)
    // From this we can see we have two choice
    // dp[i, j] = max(dp[i-1, j], dp[i, j-1]) + cost[i, j]
    // 
    // Lets move to the intial state (0, 0)
    // dp[0, 0] = cost[0, 0]
    // 
    // Lest move to the state (1, 0)
    // since we only have one choice
    // dp[1, 0] = dp[0, 0] + cost[1, 0] 
    // 
    // I did a pretty smart thing in the solution
    // Which is initialization
    // So in above explanation I didn't add the trick
    long long sol(const vector<vector<long long>> & cost){
        const long long n = cost.size();
        const long long m = cost[0].size();
        vector<vector<long long>> dp(n+1, vector<long long>(m + 1, 0));
        // 0 intialization 
        // help in handling the base case
        // Very good trick 
        // else we need to handle number of edge cases

        for(long long i = 1; i <= n; i++){
            for(long long j = 1; j <= m; j++){
                dp[i][j] = max({dp[i-1][j], dp[i][j-1]}) + cost[i-1][j-1];
            }
        }

        // DEBUG
        // for(auto & i : dp){
        //     dbg(i);
        // }

        return dp[n][m];
    } // O(n.m)
    // This same can be done with acyclic graph
    // Graph Theory can used in number of different question
}

namespace ques09{
    // Ques 09 : 
    // here let n and k describe the sate of dp
    // n = cell number
    // k = jump made <= k
    // dp[n, k] = number of path to cell n with last jump <= k
    // 
    // Let move to some arbitrary state n and k
    // for i=1...k
    //      dp[n, k] += dp[n-i, i]
    // 
    // Let move to intital state n = 0 and k = 0
    // dp[0, 0] = 1
    // 
    // Using broadcasting
    // dp[0, :] = 1
    // dp[:, 0] = 1
    long long slow_sol(long long n){
        vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
        // i = n th cell
        // j = last jump j<=
        
        // Base Case
        for(long long i = 0; i <= n; i++){
            dp[0][i] = 1;
            dp[i][0] = 1;
        }

        for(long long i = 1; i <= n; i++){
            for(long long j = 1; j <= n; j++){
                for(long long k = 1; k <= j; k++){
                    if(i-k >= 0){
                        dp[i][j] += dp[i-k][k];
                    }
                }
            }
        }
        return dp[n][n];
    } // O(n^3)
}


// Solution
void solve(){
    // for(ll i = 1; i < 10; i++){
    //     dbg(naive::fabonacci(i));
    // }

    // for(ll i = 1; i < 10; i++){
    //     dbg(fast::fabonacci(i));
    // }
    const ll n = 10;
    vector<ll> a(n+1, 0);
    iota(a.begin(), a.end(), 0);
    vector<ll> k(n+1, 0);
    iota(k.begin(), k.end(), 1);

    // Ques 01 :
    for(auto & i : a){
        dbg(i);
        dbg(ques01::sol(i));
    }
    cerr << nline;

    // Ques 02 :
    for(auto & i : a){
        dbg(i);
        dbg(ques02::sol(i));
    }
    cerr << nline;

    // Ques 03 :
    for(auto & i : a){
        dbg(i);
        dbg(ques03::sol(i));
    }
    cerr << nline;

    // Ques 04 : (slow and fast)
    for(auto & i : a){
        for(auto & j : k){
            dbg(i);dbg(j);
            dbg(ques04::slow_sol(i, j));
            dbg(ques04::fast_sol(i, j));
        }
        cerr << nline;
    }
    // cerr << nline;

    // Ques 05 :
    dbg(ques05::sol({0,  3,  5,  6,  7,  1,  5,  4,  3,  0}));
    cerr << nline;

    // Ques 06 : (slow)
    dbg(ques06::slow_sol({0,  3,  5,  6,  7,  1,  5,  4,  3,  0}, 2));
    cerr << nline;

    // Ques 07 : 
    dbg(ques07::sol({0,  3,  5,  6,  7,  1,  5,  4,  3,  0}, 2).first);
    dbg(ques07::sol({0,  3,  5,  6,  7,  1,  5,  4,  3,  0}, 2).second);
    cerr << nline;

    // Ques 08 :
    dbg(ques08::sol({
        {0, 3, 2, 3},
        {1, 6, 5, 7},
        {2, 3, 1, 2},
        {8, 2, 1, 6},
        {3, 2, 1, 0}
    }));
    cerr << nline;

    // Ques 09 :
    dbg(ques09::slow_sol(5));
    dbg(ques09::slow_sol(2));
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