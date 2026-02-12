
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int n, dp[1 << 16];

int f(int row, int mask) {
    if(mask == (1 << n) - 1) return 0;
    if(dp[mask] != -1) return dp[mask];

    int ans = 0;
    for(int col = 0; col < n; col++) {
        if((mask & (1 << col)) == 0) {
            ans = max(ans, v[row][col] + f(row + 1, (mask | (1 << col))));
        }
    }

    return dp[mask] = ans;
}

void solve() {

    cin >> n;
    v.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    cout << f(0, 0) << '\n';

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        v.clear();
        memset(dp, -1, sizeof(dp));
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}