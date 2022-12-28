#include <bits/stdc++.h>
using namespace std;

// 1 <= L <= R <= 10 ^ 9
// 0 <= R - L <= 10 ^ 5
vector<long long> segmented_sieve(long long L, long long R) {
    long long len = R - L + 1;
    long long N = ceil(sqrt(R)) + 1;

    // Sieve
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for(long long i = 2; i * i < N; i++) {
        for(long long j = i; i * j < N; j++) {
            is_prime[i * j] = false;
        }
    }
    
    // Primes
    vector<long long> primes;
    for(long long i = 2; i < N; i++) {
        if(is_prime[i]) primes.push_back(i); 
    }

    // Segmented Sieve
    is_prime = vector<bool>(len, true);
    for(auto& p: primes) {
        long long l = (L + p - 1) / p;
        for(long long i = max(l, 2LL); i * p <= R; i++) {
            is_prime[(i * p) - L] = false;
        }
    }

    // Primes in Range
    vector<long long> rprimes;
    if(L == 1) is_prime[0] = false;
    for(long long i = 0; i < len; i++) {
        if(is_prime[i]) rprimes.push_back(i + L);
    }

    return rprimes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}