
#include <bits/stdc++.h>
using namespace std;

int subordinate[200005];
bool vis[200005];
 
void dfs(int node, vector<vector<int>>& adj) {
    if(vis[node]) return;
 
    vis[node] = true;
    for(auto child : adj[node]) {
        subordinate[node]++;
        dfs(child,adj);
        subordinate[node] += subordinate[child];
    }
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
 
    dfs(1, adj);
 
    for(int i = 1; i <= n; i++) {
        cout << subordinate[i] << " \n"[i == n];
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