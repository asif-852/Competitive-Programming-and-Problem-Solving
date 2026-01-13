
// Approach 1: Iterative DP
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int a, b;
    cin >> a >> b;
    int n = max(a + 1, b + 1);
    vector<vector<long long>> dp(n, vector<long long>(n, 1e18));
    for(int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            for(int k = 1; k <= i; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
            }
            for(int k = 1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
        }
    }
    cout << dp[a][b] << '\n';
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


// Approach 2: Recursive DP with Memoization

/*
#include <bits/stdc++.h>
using namespace std;

long long dp[501][501];
 
long long minMoves(int a, int b) {
    if(a == b) return 0;
 
    if(dp[a][b]) return dp[a][b];
 
    long long ans = 1e18;
    for(int i = 1; i < a; i++) {
        ans = min(ans, 1 + minMoves(i, b) + minMoves(a - i, b));
    }
    for(int i = 1; i < b; i++) {
        ans = min(ans, 1 + minMoves(a, i) + minMoves(a, b - i));
    }
 
    return dp[a][b] = ans;
}


void solve() {
    int a, b;
    cin >> a >> b;
    cout << minMoves(a, b) << '\n';
    vector<vector<int>> matrix(n, vector<int>(m));
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

*/