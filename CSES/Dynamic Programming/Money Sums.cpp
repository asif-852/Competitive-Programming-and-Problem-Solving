
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for(auto &x : coins) cin >> x;
 
    int X = accumulate(coins.begin(), coins.end(), 0);
 
    vector<bool> dp(X + 1, 0);
    dp[0] = 1;
    for(auto k : coins) {
        for(int i = X; i >= 0; i--) {
            if(dp[i]) {
                dp[i + k] = 1;
            }
            // debug(i, dp);
            // cout<<'\n';
        }
    }
 
    cout << count(dp.begin() + 1, dp.end(), 1) << '\n';
    for(int i = 1; i <= X; i++) {
        if(dp[i]) {
            cout << i << " \n"[i == X];
        }
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

