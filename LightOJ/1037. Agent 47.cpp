
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> health;
int n, dp[1 << 16];

int f(int mask) {
    if(mask == (1 << n) - 1) return 0;
    if(dp[mask] != -1) return dp[mask];

    int ans = 1e9;
    for(int col = 0; col < n; col++) {
        if((mask & (1 << col)) == 0) {
            int damage = 1;
            for(int row = 0; row < n; row++) {
                if((mask & (1 << row))) {
                    damage = max(damage, v[row][col]);
                }
            }
            int cost = round(ceil((health[col]) / damage));
            ans = min(ans, cost + f(mask | (1 << col)));
        }
    }

    return dp[mask] = ans;
}

void solve() {

    cin >> n;
    health.resize(n);
    for(auto& x : health) cin >> x;
    v.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            v[i][j] = c - '0';
        }
    }
    cout << f(0) << '\n';

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        memset(dp, -1, sizeof(dp));
        health.clear();
        v.clear();
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}