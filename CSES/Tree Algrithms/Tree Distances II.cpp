
// Approach : Tree re-rooting

#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<long long> dp, subtree_sz;
vector<vector<int>> adj;
 
void dfs(int node, int par) {
    for(auto child : adj[node]) {
        if(child ^ par) {
            dfs(child, node);
            subtree_sz[node] += subtree_sz[child];
            dp[node] += dp[child] + subtree_sz[child];
        }
    }
}
 
void re_root(int node, int par) {
    for(auto child : adj[node]) {
        if(child ^ par) {
            long long a = dp[node], b = subtree_sz[node];
 
            // Undoing the contribution of the child for the current root
            dp[node] -= dp[child];
            dp[node] -= subtree_sz[child];
            subtree_sz[node] -= subtree_sz[child];
 
            // Child will be the new root
            subtree_sz[child] += subtree_sz[node];
            dp[child] += dp[node] + subtree_sz[node];
 
            re_root(child, node);
 
            // Restoring the values
            dp[node] = a;
            subtree_sz[node] = b;
        }
    }
}
 
void solve() {
 
    cin >> n;
    dp.resize(n + 1, 0);
    subtree_sz.resize(n + 1, 1);
    adj.resize(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Calculating answer for the first root
    dfs(1, -1);
 
    // Calculating answer for other roots
    re_root(1, -1);
    for(int i = 1; i <= n; i++) {
        cout << dp[i] << " \n"[i == n];
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
