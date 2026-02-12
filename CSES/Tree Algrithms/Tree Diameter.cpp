
#include <bits/stdc++.h>
using namespace std;
 
 
void BFS(int s, vector<vector<int>>& adj, vector<int>& level) {
    level[s] = 0;
 
    queue<int> q;
    q.push(s);
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();
 
        for(auto v : adj[u]) {
            if(level[v] == 1e9) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}
 
 
void solve() {
 
    int n;
    cin >> n;
    vector<vector<int> > adj(n + 1);
    vector<int> level(n + 1, 1e9);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(1, adj, level);
    int end1 = max_element(level.begin() + 1, level.end()) - level.begin();
    level.assign(n + 1, 1e9);
    BFS(end1, adj, level);
    cout << *max_element(level.begin() + 1, level.end()) << '\n';
 
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
