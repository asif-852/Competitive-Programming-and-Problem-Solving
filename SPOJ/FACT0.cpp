
#include <bits/stdc++.h>
using namespace std;

void get_prime_factors(vector<pair<long long, long long>>& primes, long long n) {
    for(long long i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            long long cnt = 0;
            while(n % i == 0) {
                n /= i;
                cnt++;
            }
            primes.push_back({i, cnt});
        }
    }
    if(n > 1) {
        primes.push_back({n, 1});
    }
}

void solve() {
    while(1) {
        long long n;
        cin >> n;
        if(n == 0) break;
 
        vector<pair<long long, long long>> primes;
        get_prime_factors(primes, n);
        for(auto [prime, cnt] : primes) {
            cout << prime << "^" << cnt << " ";
        }
        cout << '\n';
    }
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