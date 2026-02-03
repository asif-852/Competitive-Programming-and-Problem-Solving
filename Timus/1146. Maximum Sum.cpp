
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        partial_sum(v[i].begin(), v[i].end(), v[i].begin());
    }

    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= n; i++) {
            v[i][j] += v[i - 1][j];
        }
    }
    
    int ans = -1e9;
    for(int i1 = 0; i1 < n; i1++) {
        for(int j1 = 0; j1 < n; j1++) {
            for(int i2 = i1 + 1; i2 <= n; i2++) {
                for(int j2 = j1 + 1; j2 <= n; j2++) {
                    ans = max((v[i2][j2] - v[i1][j2] - v[i2][j1] + v[i1][j1]), ans);
                }
            }
        }
    }
    cout << ans << '\n';
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