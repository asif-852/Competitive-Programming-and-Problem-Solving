
#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<int> visited, ans;
bool possible = true;

void dfs(int u) {
    visited[u] = 1; // Mark as visiting
    for(auto v : adj[u]) {
        if(visited[v] == 1) {
            possible = false;
        }
        if(visited[v] == 0) {
            dfs(v);
        }
    }
    visited[u] = 2; // Mark as visited
    ans.push_back(u);
}

void solve() {

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, 0);
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    if(!possible) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    
    reverse(ans.begin(), ans.end());
    for(auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << " \n"[next(it) == ans.end()];
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