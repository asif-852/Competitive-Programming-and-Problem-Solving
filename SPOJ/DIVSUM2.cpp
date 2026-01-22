
#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime(1e8 + 15, 1);
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



long long SOD(long long n) {
    long long sum = 1;

    for(auto p : primes) {
        if(p * p > n) break;

        if(n % p == 0) {
            long long cnt = 0;
            while(n % p == 0) {
                n /= p;
                cnt++;
            }
            sum *= (pow(p, cnt + 1) - 1) / (p - 1);
        }
    }
    if(n > 1) sum *= (n + 1);
    return sum;
}


void solve() {
    long long n;
    cin >> n;
    cout << SOD(n) - n << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(1e8 + 10);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
