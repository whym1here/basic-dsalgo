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
class Stack{
private:
    ll *ptr = nullptr;
    ll size = 0;
    ll n = 0;
public:
    void push(ll x){
        if(n == size){
            ll *new_ptr = new ll[2*n];
            for(ll i = 0; i < n; i++){
                new_ptr[i] = ptr[i];
            }
            if(ptr != nullptr){
                ll* del_ptr = ptr;
                delete[] del_ptr;
            }
            ptr = new_ptr;
        }
        size++;
        ptr[n++] = x; 
    }

    ll pop(){
        ll res = ptr[--n];
        if (n < size/4){
            if(ptr == nullptr){
                cerr<<"INVALID OPERATION"<<endl;
                return -LLONG_MAX;

            }
            ll *new_ptr = new ll[size/2];
            for(ll i = 0; i < n; i++){
                new_ptr[i] = ptr[i];
            }
            ptr = new_ptr;
        }
        size--;
        return res;
    }

    void display(){
        prl('[');
        for(ll i = 0; i < n; i++){
            prl(ptr[i]);
        }
        pr(']');
    }

    bool empty(){
        return (size > 0) ? false : true; 
    }
};

class Queue{
private:
    Stack s1;
    Stack s2;
public:
    void add(ll x){
        s2.push(x);
    }
    ll remove(){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
        return s1.pop();
    }
};

// Functions


// Solution
void solve(){
    Stack s1;
    for(ll i = 1; i < 11; i++){
        // prl(s1.empty());
        s1.push(i*i);
        s1.display();
    }
    for(ll i = 1; i < 11; i++){
        prl(s1.pop());  
        s1.display();
        // prl(s1.empty());
    }

    Queue q1;
    for(ll i = 1; i < 11; i++){
        q1.add(i*i);
    }
    for(ll i = 1; i < 11; i++){
        prl(q1.remove());
    }
    prl('\n');
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