
// Approach: Segmented Sieve Algorithm
#include <bits/stdc++.h>
using namespace std;
 
 
vector<bool> isPrime(1e6 + 15, 1);
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
 
    int l, r;
    cin >> l >> r;
    vector<int> segment(r - l + 1, 1);
    for(auto p : primes) {
        if(p * p > r) break;
 
        int start = (l / p) * p;
        if(p >= l and p <= r) start = 2 * p;
 
        for(int j = start; j <= r; j += p) {
            if(j < l) continue;
            segment[j - l] = 0;
        }
    }
 
    for(int i = l; i <= r; i++) {
        if(segment[i - l] && i != 1) {
            cout << i << '\n';
        }
    }
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(1e6 + 10);
 
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
} 