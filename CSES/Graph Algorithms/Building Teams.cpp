
#include <bits/stdc++.h>
using namespace std;

vector<bool> vis(1e5 + 5, 0);
 
void BFS(int s, vector<vector<int>> &adj, vector<int> &level) {
    level[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();
 
        for(auto v : adj[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                level[v] = 1 - level[u];
                q.push(v);
            } else {
                if(abs(level[v] - level[u]) != 1) {
                    cout << "IMPOSSIBLE" << '\n';
                    exit(0);
                }
            }
        }
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> level(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            BFS(i, adj, level);
        }
    }
 
    //debug(adj);
    //debug(level);
 
    for(int i = 1; i <= n; i++) {
        cout << level[i] + 1 << " \n"[i == n];
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