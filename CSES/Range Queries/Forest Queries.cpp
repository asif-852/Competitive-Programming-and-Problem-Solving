
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    map<char, int> val;
    val['.'] = 0;
    val['*'] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            v[i][j] = val[c];
        }
    }

    for(int i = 1; i <= n; i++) {
        partial_sum(v[i].begin(),v[i].end(),v[i].begin());
    }

    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= n; i++) {
            v[i][j] += v[i - 1][j];
        }
    }
 
    while(q--) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        --i1, --j1;
        cout << v[i2][j2] - v[i1][j2] - v[i2][j1] + v[i1][j1] << '\n';
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