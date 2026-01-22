
#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<int> color;
bool bad;
 
void DFS(int u, int c) {
    color[u] = c;
 
    for(int v : adj[u]) {
        if(color[v] == -1) {
            DFS(v, 1 - c);
        } else if(color[v] == color[u]) {
            bad = true;
            return;
        }
    }
}
 
void solve() {
    adj.clear();
    adj.resize(n + 1);
    color.assign(n + 1, -1);
    bad = false;
    
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            DFS(i, 0);
        }
    }
 
    cout << (bad ? "Suspicious bugs found!" : "No suspicious bugs found!") << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Scenario #" << i << ":\n";
        solve();
    }
 
    return 0;
}