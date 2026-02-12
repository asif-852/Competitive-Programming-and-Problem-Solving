
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

vector<int> prime_factors[N];
vector<long long> multiples(N);
vector<bool> isPrime(N, 1);
vector<int> primes;

void sieve(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) primes.push_back(i);
    }
}

long long non_coprimes(int x) {
    long long ans = 0;
    int sz = prime_factors[x].size();
    for(int i = 1; i < (1 << sz); i++) {
        int val = 1, cnt = 0;
        for(int j = 0; j < sz; j++) {
            if(i & (1 << j)) {
                val *= prime_factors[x][j];
                cnt++;
            }
        }
        (cnt & 1) ? ans += multiples[val] : ans -= multiples[val];
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(N), v;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v.push_back(val);
        cnt[val]++;
    }

    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            if(cnt[j]) {
                multiples[i] += cnt[j];
            }
        }
    }
    
    long long ans = 0;
    for(auto x : v) {
        if(x == 1) {
            ans += n - 1;
        } else {
            ans += n - non_coprimes(x);
        }
    }
    cout << ans / 2 << '\n';
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(1e6);

    for(int i = 2; i < N; i++) {
        int num = i;
        for(int p : primes) {
            if(p * p > num) break;

            if(num % p == 0) {
                prime_factors[i].push_back(p);
                while(num % p == 0) num /= p;
            }
        }
        if(num > 1) {
            prime_factors[i].push_back(num);
        }
    }

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}