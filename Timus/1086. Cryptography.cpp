
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<bool> isPrime(N + 1, 1);
vector<long long> primes;

void sieve(long long n) {
    for(long long i = 2; i * i <= n; i++) {
        if(isPrime[i] == 1) {
            for(long long j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    for(long long i = 2; i <= n; i++) {
        if(isPrime[i]) primes.push_back(i);
    }
}

void solve() {

    int k;
    cin >> k;
    cout << primes[k - 1] << '\n';

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(N);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}