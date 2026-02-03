
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
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; i++) {
        while(1) {
            int x;
            cin >> x;
            if(x == 0) break;
            adj[i].push_back(x);
        }
    }
    //debug(adj);
    for(int i = 1; i <= n; i++) {
        if(adj[i].empty()) {
            cout << 0 << '\n';
            return;
        }
    }
    vector<int> level(n + 1, 1e9);
    for(int i = 1; i <= n; i++) {
        if(level[i] == 1e9) {
            BFS(i, adj, level);
        }
    }
    //debug(level);

    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(level[i] % 2) ans.push_back(i);
    }
    cout << ans.size() << '\n';
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