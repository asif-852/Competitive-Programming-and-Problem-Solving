
#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;

void solve() {
    int n, X;
    cin >> n >> X;
    vector<int> coins(n);
    for(auto &x : coins) cin >> x;
 
    vector<int> dp(X + 1, 0);
    dp[0] = 1;
    for(auto k : coins) {
        for(int i = 1; i <= X; i++) {
            if(i - k >= 0) {
                dp[i] += dp[i - k];
                dp[i] %= MOD;
            }
            // debug(dp);
        }
    }
 
    cout << dp[X] << '\n';

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