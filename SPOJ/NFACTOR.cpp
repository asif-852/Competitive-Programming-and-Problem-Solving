
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 10;
 
vector<bool> isPrime(N + 5, 1);
vector <long long> primes;
vector<int> prime_factors(N + 5, 0);
vector<int> exactly[20];
 
void sieve(long long n) {
    for(long long i = 2; i * i <= n; i++) {
        if(isPrime[i] == 1){
            for(long long j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
 
    for(long long i = 2; i <= n; i++){
        if(isPrime[i]) primes.push_back(i);
    }
}

void solve() {
    //debug(exactly[0]);
    int a, b, n;
    cin >> a >> b >> n;
    int val1 = lower_bound(exactly[n].begin(), exactly[n].end(), a) - exactly[n].begin();
    int val2 = upper_bound(exactly[n].begin(), exactly[n].end(), b) - exactly[n].begin();
    cout << val2 - val1 << '\n';
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(1e6 + 10);
 
    for(auto p : primes) {
        for(int i = p; i <= N; i += p) {
            prime_factors[i]++;
        }
    }
 
    for(int i = 0; i <= N; i++) {
        exactly[prime_factors[i]].push_back(i);
    }

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}