
#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, 1e18));
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    while(m--) {
        long long u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << (dist[a][b] == 1e18 ? -1 : dist[a][b]) << '\n';
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
