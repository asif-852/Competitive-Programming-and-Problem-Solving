
#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<long long>> dp(n, vector<long long>(n));
    dp[0][0] = (v[0][0] != '*') ? 1 : 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i != 0 || j != 0) && v[i][j] != '*' ) {
                dp[i][j] = ((i - 1 >= 0) ? dp[i - 1][j] : 0) + ((j - 1 >= 0) ? dp[i][j - 1] : 0);
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1] << '\n';

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