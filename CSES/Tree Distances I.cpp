

#ifndef ONLINE_JUDGE
#include <\Users\asifa\OneDrive\Documents\Debugging.h>
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...) 42
#endif




















// author : Rohanbiswas
#include <bits/stdc++.h>
using namespace std;

vector<int> ans(2e5 + 1, 0);

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
                ans[v] = max(ans[v], level[v]);
                q.push(v);
            }
        }
    }
}

void solve() {

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> level(n + 1, 1e9);
    BFS(1, adj, level);
    int end1 = max_element(level.begin() + 1, level.end()) - level.begin();
    level.assign(n + 1, 1e9);
    BFS(end1, adj, level);
    int end2 = max_element(level.begin() + 1, level.end()) - level.begin();
    //debug(end1,end2);

    level.assign(n + 1, 1e9);
    BFS(end1, adj, level);
    level.assign(n + 1, 1e9);
    BFS(end2, adj, level);

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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
