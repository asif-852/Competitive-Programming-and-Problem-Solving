
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
 
    int cnt = 0;
    for(long long i = 2; i <= n; i++) {
        if(isPrime[i]) {
            cnt++;
            if(cnt % 100 == 1) {
                cout << i << '\n';
            }
        }
    }
}
 

void solve() {
    sieve(1e8);
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}