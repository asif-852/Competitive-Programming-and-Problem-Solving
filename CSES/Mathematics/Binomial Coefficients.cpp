
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
 
long long ModularInverse(long long a, long long m) {
    long long t1 = 0, t2 = 1, mod = m;
    while(a != 0) {
        long long q = m / a;
        m -= q * a;
        swap(a, m);
        t1 -= q * t2;
        swap(t1, t2);
    }
 
    return (t1 < 0) ? t1 + mod : t1;
}
 
void solve() {
 
    int n, k;
    cin >> n >> k;
    long long ans = factorial[n];
    ans *= ModularInverse(factorial[k], MOD);
    ans %= MOD;
    ans *= ModularInverse(factorial[n - k], MOD);
    ans %= MOD;
    cout << ans << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    generate_factorials(1e6);
 
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
 
    return 0;
}