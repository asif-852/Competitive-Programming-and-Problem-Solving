
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n, X;
    cin >> n >> X;
    vector<int> coins(n);
    for(auto &x : coins) cin >> x;
 
    vector<int> dp(X + 1, 2e9);
    dp[0] = 0;
    for(int i = 1; i <= X; i++) {
        for(auto k : coins) {
            if(i - k >= 0) {
                dp[i] = min(dp[i], dp[i - k] + 1);
            }
        }
    }
    cout << ((dp[X] == 2e9) ? -1 : dp[X]) << '\n';
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