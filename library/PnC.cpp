#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

long long norm(long long x, long long m = mod) {
    return (m + (x % m)) % m;
}

long long power(long long a, long long b, long long m = mod) {
    a = norm(a);
    long long res = 1;
    while(b > 0) {
        if((b & 1) > 0) res = norm(res * a);
        a = norm(a * a);
        b >>= 1;
    }
    return res;
}

class PnC {
public:
    vector<long long> f = {1}, invf = {1};
    long long m;
    
    PnC(long long _m) {
        m = _m;
    }

    long long fact(long long x) {
        while((int)f.size() <= x) {
            f.push_back(norm(f.size() * 1LL * f.back(), m));
        }
        return f[x];
    }

    long long inverse(long long x) {
        return power(x, m - 2, m);
    }

    long long inv(long long x) {
        while((int)invf.size() <= x) {
            invf.push_back(norm(invf.back() * 1LL * inverse(invf.size()), m));
        }
        return invf[x];
    }

    long long nPr(long long n, long long r) {
        assert(n >= r);
        return norm(fact(n) * inv(n - r), m);
    }

    long long nCr(long long n, long long r) {
        return norm(nPr(n, r) * inv(r), m);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
