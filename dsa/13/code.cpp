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
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// CLASS 
template<typename T>
class Graph{
public:
    vector<vector<pair<T,T>>> adj_list;

    Graph(T n){
        adj_list = vector<vector<pair<T,T>>>(n);
    }

    void add(T u, T v, T wt){
        adj_list[u].push_back({v, wt});
        adj_list[v].push_back({u, wt});
    }

    void display(){
        for(T i = 0; i < adj_list.size(); i++){
            cerr << "# node : " << i << endl;
            for(T j = 0; j < adj_list[i].size(); j++){
                cerr << "node : " << adj_list[i][j].first << "  wt : " << adj_list[i][j].second << endl; 
            }
            cerr << endl;
        }
    }

};

// Functions
namespace ques01{
    // NOTE : working but needs to be understood
    // Traveling Salesman Problem
    // 
    // s = subset number (eg. 00001111 = 15 )
    // v = finish vertex(or node) 
    // dp[s, v] =  minimum distance with subset s and ending at v
    // dp[0, 0] = 0 
    // 
    long long traveling_salesman(const Graph<long long> & gr){
        const long long inf = 1e10;
        const long long n = gr.adj_list.size();
        long long rows = (1<<n), cols = n;
        vector<vector<long long>> dp(rows, vector<long long>(cols, inf));
        
        // Base case
        for(long long i = 0; i < n; i++){
            dp[(1<<i)][i] = 0;
        }

        for(long long x = 1; x < (1<<n); x++){
            for(long long v = 0; v < n; v++){
                for(auto & [u, wt] : gr.adj_list[v]){
                    if((x&(1<<u)) == 0){
                        long long y = x | (1<<u);
                        dp[y][u] = min({
                            dp[y][u], dp[x][v] + wt
                        });
                    }
                }
            }
        }

        // Debug
        // for(auto & i : dp){
        //     dbg(i);
        // }

        long long res = inf;
        for(long long v = 0; v < n; v++){
            res = min({
                res, dp[(1<<n)-1][v]
            });
        }
        return res;
    } // O(n.(2^(n)).k)
}

namespace ques02{
    // NOT WORKING

    bool comp(const long long p, const long long q, const long long n){
        if((p&q) != 0){
            return false;
        }
        long long x = ((~p)&(~q))&((1<<n)-1);
        if(x%3 != 0){
            return false;
        }
        long long y = x/3;
        if((y&(y<<1)) != 0){
            return false;
        }
        return true;
    } // O(1)

    // Parquet Problem
    // (i, p) -> (i+1, p)
    // dp[i, p] = number of ways to fill first i columns with profile p
    long long full_profile_parquet_problem(const long long n, const long long m){
        vector<vector<long long>> dp(m, vector<long long>((1<<n)));
        
        // Base Case
        dp[0][0] = 1;
        
        for(long long i =0; i < m; i++){
            for(long long p = 0; p < (1<<n); p++){
                for(long long q = 0; q < (1<<n); q++){
                    if(comp(p, q, n)){
                        dp[i+1][q] += dp[i][p];
                    }
                }
            }
        } // O(m.(4^n))

        return dp[m][0];
    }

    

    long long broken_profile_parquet_problem(const long long n, const long long m){
        vector<vector<vector<long long>>> dp(m+1, vector<vector<long long>>(n+1, vector<long long>((1<<n)+1)));
        
        // Base Case
        dp[0][0][0] = 1;

        for(long long i = 0; i < m; i++){
            for(long long j = 0; j < n; j++){
                for(long long p = 0; p < (1<<n); p++){
                    if((p&(1<<j)) != 0){
                        long long q = p - (1<<j);
                        dp[i][j+1][q] += dp[i][j][p];
                    }
                    else{
                        long long q = p + (1<<j);
                        dp[i][j+1][q] += dp[i][j][p];
                        if( (j < n-1) and (p&(1<<(j+1))) == 0){
                            q = p+(1<<(j+1));
                            dp[i][j+1][q] += dp[i][j][p];
                        }
                    }
                }
            }
            for(long long p = 0; p < (1<<n); p++){
                dp[i+1][0][p] = dp[i][n][p];
            }
        }

        return dp[m][0][0];
    } // O(m.n.(2^n))
}



// Solution
void solve(){
    const long long n = 8LL;
    Graph<long long> g(n);
    
    g.add(0, 1, 3);
    g.add(0, 2, 4);
    g.add(0, 3, 7);

    g.add(1, 2, 2);
    g.add(1, 4, 5);

    g.add(2, 4, 2);
    g.add(2, 5, 3);

    g.add(3, 5, 5);
    g.add(3, 6, 6);
    
    g.add(4, 5, 3);
    g.add(4, 7, 8);

    g.add(5, 6, 7);

    g.add(6, 7, 5);

    g.display();

    dbg(ques01::traveling_salesman(g));
    cerr << endl;

    dbg(ques02::full_profile_parquet_problem(3, 4));
    dbg(ques02::full_profile_parquet_problem(4, 5));
    dbg(ques02::full_profile_parquet_problem(6, 8));
    dbg(ques02::full_profile_parquet_problem(8, 9));

    dbg(ques02::broken_profile_parquet_problem(3, 4));
    dbg(ques02::broken_profile_parquet_problem(4, 5));
    dbg(ques02::broken_profile_parquet_problem(6, 8));
    dbg(ques02::broken_profile_parquet_problem(8, 9));
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