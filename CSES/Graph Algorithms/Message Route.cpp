
#include <bits/stdc++.h>
using namespace std;
 
void BFS(int s, vector<vector<int>>& adj, vector<int>& level, vector<int>& parent) {
    level[s] = 0;
 
    queue<int> q;
    q.push(s);
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();
 
        for(auto v : adj[u]) {
            if(level[v] == 1e9) {
                level[v] = level[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
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
    vector<int> level(n + 1, 1e9);
    vector<int> parent(n + 1, -1);
    BFS(1, adj, level, parent);
 
    if(level[n] == 1e9) {
        cout << "IMPOSSIBLE\n";
        return;
    }
 
    cout << level[n] + 1 << '\n';
    vector<int> path;
    int node = n;
    while(node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << " \n"[i == path.size() - 1];
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
 
    return 0;
}