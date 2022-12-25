#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e7 + 1;
int spf[MXN];
// vector<int> primes;

void init() {
    iota(spf, spf + MXN, 0);
    spf[0] = -1, spf[1] = 1;
    for(int i = 2; i * 1LL * i < MXN; i++) {
        if(spf[i] == i) {
            if(i * 1LL * i < MXN) {
                for(int j = i * i; j < MXN; j += i) {
                    if(spf[j] == j) spf[j] = i;
                }
            }
        }
    }
    // primes.push_back(2);
    // for(int i = 3; i < MXN; i += 2) {
    //     if(spf[i] == i) primes.push_back(i);
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}