
#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
vector<long long> factorial(1e6 + 1, 1);
 
void generate_factorials(int n) {
    for(int i = 1; i <= n; i++) {
        factorial[i] = i * factorial[i - 1];
        factorial[i] %= MOD;
    }
}

long long inverse(long long i) {
    if(i == 1) return 1;
    return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    long long ans = factorial[n + m - 1];
    ans *= inverse(factorial[n - 1]);
    ans %= MOD;
    ans *= inverse(factorial[m]);
    ans %= MOD;
    cout << ans << '\n';

}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    generate_factorials(1e6);

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}