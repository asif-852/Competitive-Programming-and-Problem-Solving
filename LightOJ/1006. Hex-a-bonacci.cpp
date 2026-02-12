
#include <bits/stdc++.h>
using namespace std;

const int MOD = 10000007;

int a, b, c, d, e, f, n;
long long dp[10005];

long long fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;

    if(dp[n] != -1) 
        return dp[n];
    
    long long res = 0;
    for(int i = 1; i <= 6; i++) {
        res = (res + fn(n - i)) % MOD;
    }

    return dp[n] = res;
}


void solve() {

    cin >> a >> b >> c >> d >> e >> f >> n;
    memset(dp, -1, sizeof(dp));
    cout << fn(n) % MOD << '\n';

}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}