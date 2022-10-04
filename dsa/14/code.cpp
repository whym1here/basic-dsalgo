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

// Class
namespace naive {
    class hashtable{
    private:
        long long m; // 5101 is a good hash to show this implementation
        vector<ll> lookup;
    public:
        // Constructor
        hashtable(long long n, long long m){
            this->lookup = vector<long long>(n, 0);
            this->m = m;
        }

        // Just to show the concept work
        // do not use it in real life
        hashtable(long long n){
            this->lookup = vector<long long>(n, 0);
            this->m = n;
        }
        
        // Hash Function
        long long h(long long x){
            return (x%(this->m));
        }
        
        // Overloading [] operator
        // & is used so that lhs can be change by using assignment
        // can be used as both put(key, value) as {ht[key] = value} and get(key) as {ht[key]} 
        long long& operator[](long long key){
            return this->lookup[h(key)];
        }

        void debug(){
            cerr << "m = " << this->m << "\n";
            cerr << "lookup = [";
            for(long long i = 0; i < this->lookup.size(); i++){
                cerr << this->lookup[i] << (i != lookup.size()-1 ? ", " : "");
            }
            cerr << "]\n";
            cerr << "\n";
        }
    };
}

namespace better {
    class hashtable{
    private:
        long long m; // 5101 is a good hash to show this implementation
        vector<vector<pair<long long, long long>>> lookup;
    public:
        // Constructor
        hashtable(long long n, long long m){
            this->lookup = vector<vector<pair<long long, long long>>>(n);
            this->m = m;
        }

        // Just to show the concept work
        // do not use it in real life
        hashtable(long long n){
            this->lookup = vector<vector<pair<long long, long long>>>(n);
            this->m = n;
        }
        
        // Hash Function
        long long h(long long x){
            return (x%(this->m));
        }

       long long& operator[](long long key){
            long long hkey = h(key);
            // auto & ref_row = this->lookup[hkey];
            for(auto & [x, y] : this->lookup[hkey]){
                if(x == key){
                    return y;
                }
            }
            this->lookup[hkey].push_back({key, 0});
            return this->lookup[hkey][this->lookup[hkey].size()-1].second;
        }

        void debug(){
            for(long long i = 0; i < this->lookup.size(); i++){
                cerr << "lookup[" << i <<"] = [";
                for(long long j = 0; j < this->lookup[i].size(); j++){
                    cerr << "{" << this->lookup[i][j].first << ", " << this->lookup[i][j].second << "}";
                    cerr << (j != this->lookup[i].size()-1 ? ", " : "");
                }
                cerr << "]\n";
            }

            cerr << "\n";
        }
    };
}

namespace nice {
    // Open 
    class hashtable {
    private:
        vector<pair<long long,long long>> lookup;
        long long tempsol;
    public:
        // good enough hash function for the showcase of the concept
        long long h(long long key){
            const long long m = 5051 , P = 2000 , A = 8191;
            // dbg((((key*A)%P)%m)%(this->tempsol));
            return (((key*A)%P)%m)%(this->tempsol);
        }

        // Constructor 
        hashtable(long long n){
            this->tempsol = n + 1;
            this->lookup = vector<pair<long long,long long>>(n+1, {0, 0});
        }

        long long& operator[](long long key){
            long long hkey = h(key);
            long long i = hkey, z_idx = -1LL;

            while(this->lookup[i].first != 0 and this->lookup[i].second != 0){
                if(this->lookup[i].first == key){
                    return this->lookup[i].second;
                }
                i = (i+1)%(this->lookup.size());
            }

            // If value does not exist
            this->lookup[i].first = key;
            return this->lookup[i].second;
        }

        void debug(){
            cerr << "lookup = [";
            for(long long i = 0; i < this->lookup.size(); i++){
                cerr << "{" << this->lookup[i].first << ", " << this->lookup[i].second << (i != this->lookup.size()-1? "}, ": "}" );
            }
            cerr << "]\n";
            cerr << "\n";
        }

    };
}

// Functions


// Solution
void solve(){
    naive::hashtable h1(10, 5150);
    h1[2] = 11;
    h1[5150] = 2002;
    pr(h1[5150]);
    h1.debug();

    better::hashtable h2(11);
    h2[0] = 1;
    h2[11] = 2;
    h2[22] = 3;
    h2[33] = 4;
    h2[1] = 11;
    h2[12] = 22;
    h2[23] = 33;
    h2[34] = 44;
    dbg(h2[34]);
    h2.debug();

    nice::hashtable h3(10);
    long long t = 10;
    long long st = 10;
    while(t--){
        h3[st] = st*2;
        st += 3;
    }
    t = 10;
    st = 10;
    while(t--){
        cerr << "[" << st << "] = " << h3[st] << "\n";
        st += 3;
    }
    h3.debug();

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