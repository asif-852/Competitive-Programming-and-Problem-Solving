
#include <bits/stdc++.h>
using namespace std;
 
void dijkstra(int s, vector<vector<pair<int, long long>>>& adj, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
 
        if(d > dist[u]) continue;
 
        for(auto [v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
 
    vector<long long> dist(n + 1, 1e18);
    dijkstra(1, adj, dist);
 
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " \n"[i == n];
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