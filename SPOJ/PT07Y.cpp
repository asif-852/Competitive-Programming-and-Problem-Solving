
#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[100005];
bool vis[100005];
 
void dfs(int node) {
    if(vis[node]) return;
 
    vis[node] = true;
    for(auto neighbour : adj[node]) {
        dfs(neighbour);
    }
}
 
int connected_components (int nodes) {
    int cnt = 0;
    for(int i = 1; i <= nodes; i++) {
        if(vis[i]) continue;
        dfs(i);
        cnt++;
    }
 
    return cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << ((m == n - 1 && connected_components(n) == 1) ? "YES" : "NO") << '\n';
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