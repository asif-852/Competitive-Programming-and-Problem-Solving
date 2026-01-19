
#include <bits/stdc++.h>
using namespace std;
 
 
vector<bool> vis(100001);
vector<int> path;
 
bool dfs(int node, int parent, vector<vector<int>>& adj) {
    vis[node] = true;
    path.push_back(node);
 
    for(int neighbour : adj[node]) {
        if(!vis[neighbour]) {
            if(dfs(neighbour, node, adj)) {
                return true;
            }
        }
        else if(neighbour != parent) {
            int idx = path.size() - 1;
            while(path[idx] != neighbour) {
                --idx;
            }
            path.erase(path.begin(), path.begin() + idx);
            return true;
        }
    }
 
    path.pop_back();
    return false;
}
 
 
void solve() {
 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for(int i = 1; i <= n; i++) {
        if(!vis[i] && dfs(i, 0, adj)) {
            cout << path.size() + 1 << '\n';
            for(auto u : path) {
                cout << u << " ";
            }
            cout << path[0] << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
 
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
