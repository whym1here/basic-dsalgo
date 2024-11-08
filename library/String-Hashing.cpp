#include<bits/stdc++.h>
using namespace std;

// long long mod0 = 1000000007, mod1 = 987654347;
// long long p0 = 31, p1 = 37;
long long mod0 = 127657753, mod1 = 987654319;
long long p0 = 137, p1 = 277;
vector<array<long long, 2>> pw;
vector<array<long long, 2>> ipw;

long long h(char c) {
    return c; // return c - 'a' + 1;
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

long long inv(long long a, long long m) {
    // a is prime and a mod m != 0
    // a ^ m       === a      (mod m) 
    // a ^ (m - 2) === a ^ -1 (mod m)
    return binpow(a, m - 2, m);
}

// Till the limit i.e. [0, limit]
void init(int limit) {
    if(pw.empty()) pw.push_back({1, 1});
    while((int)pw.size() < limit + 1) {
        pw.push_back({
            (pw.back()[0] * p0) % mod0, 
            (pw.back()[1] * p1) % mod1
        });
    } 
    if(ipw.empty()) {
        ipw.push_back({1, 1});
        ipw.push_back({
            inv(p0, mod0),
            inv(p1, mod1)
        });
    }
    while((int)ipw.size() < limit + 1) {
        ipw.push_back({
            (ipw.back()[0] * ipw[1][0]) % mod0, 
            (ipw.back()[1] * ipw[1][1]) % mod1
        });
    }
}

class Hashing {
public:
    vector<array<long long, 2>> pre;
    int n; 

    Hashing(string s) {
        init((int)s.size() + 1);
        if(s.size() == 0) return;
        pre.push_back({(h(s[0]) * pw[0][0]) % mod0, (h(s[0]) * pw[0][1]) % mod1});
        for(int i = 1; i < (int)s.size(); i++) {
            pre.push_back({
                (pre[i - 1][0] + h(s[i]) * pw[i][0]) % mod0,
                (pre[i - 1][1] + h(s[i]) * pw[i][1]) % mod1
            });
        }
        n = (int)s.size();
    }

    array<long long, 2> get_hash(int l, int r) {
        assert(0 <= l and l <= r  and r < n);
        array<long long, 2> hs;
        hs[0] = pre[r][0] - (l - 1 >= 0? pre[l - 1][0]: 0) + mod0;
        hs[1] = pre[r][1] - (l - 1 >= 0? pre[l - 1][1]: 0) + mod1;
        hs[0] = (hs[0] * ipw[l][0]) % mod0;
        hs[1] = (hs[1] * ipw[l][1]) % mod1;
        return hs;
    }

    array<long long, 2> get_hash() {
        return get_hash(0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
