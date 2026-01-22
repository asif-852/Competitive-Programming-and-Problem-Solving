
// Approach: Dynamic Programming (Interval DP)
#include <bits/stdc++.h>
using namespace std;
 
vector<vector<long long>> dp;
vector<int> color, sum;
 
long long csum(int l, int r) {
    return (sum[++r] - sum[++l - 1]) % 100;
}
 
long long calc(int i, int j) {
    if(i >= j) return 0;
 
    if(dp[i][j] != -1) return dp[i][j];
 
    dp[i][j] = 1e18;
    for(int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j],  calc(i, k) + calc(k + 1, j) + csum(i, k) * csum(k + 1, j));
    }
    return dp[i][j];
}
 
void solve() {
    int n;
    while(cin >> n) {
        dp.clear();
        dp.resize(n, vector<long long> (n, -1));
        color.resize(n);
        sum.resize(n + 1, 0);
        for(int i = 0; i < n; i++) {
            cin >> color[i];
            sum[i + 1] = sum[i] + color[i];
        }
        cout << calc(0, n - 1) << '\n';
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