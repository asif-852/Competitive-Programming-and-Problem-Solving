
#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000003;
const int N = 1e6;

vector<long long> factorial(N + 1, 1);

void generate_factorials(int n) {
    for(int i = 1; i <= n; i++) {
        factorial[i] = i * factorial[i - 1];
        factorial[i] %= MOD;
    }
}


long long inverse(long long i) {
    if(i == 1) return 1;
    return (MOD - (MOD / i) * inverse(MOD % i) % MOD) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    long long ans = factorial[n];
    ans *= inverse(factorial[k]);
    ans %= MOD;
    ans *= inverse(factorial[n - k]);
    ans %= MOD;
    cout << ans << '\n';
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    generate_factorials(N);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}