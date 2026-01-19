
// Approach 1: Kruskal's Algorithm

#include <bits/stdc++.h>
using namespace std;
 
 
struct DSU {
    vector<int> parent, componentSize;
 
    DSU() {}
    DSU(int n) {
        init(n);
    }
 
    void init(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        componentSize.assign(n + 1, 1);
    }
 
    int find(int x) {
        while (x != parent[x]) {
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }
 
    bool same(int x, int y) {
        return find(x) == find(y);
    }
 
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        componentSize[x] += componentSize[y];
        parent[y] = x;
        return true;
    }
 
    int size(int x) {
        return componentSize[find(x)];
    }
};
 
int n, m;
vector<pair<int, pair<int, int>>> edges;
 
long long Kruskal() {
    sort(edges.begin(), edges.end());
    DSU dsu(n + 1);
    long long ans = 0;
    for(auto u : edges) {
        if(dsu.merge(u.second.first, u.second.second)) {
            ans += u.first;
        }
    }
    return (dsu.size(1) == n) ? ans : -1;
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    long long ans = Kruskal();
    cout << (ans == -1 ? "IMPOSSIBLE" : to_string(ans)) << '\n';
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




// Approach 2: Prim's Algorithm

/*

#include <bits/stdc++.h>
using namespace std;
 
long long Prim(int n, vector<vector<pair<int, int>>>& adj) {
    long long weight = 0;
    vector<long long> dist(n + 1, 1e18);
    dist[1] = 0;
    set<pair<long long, int>> q;
    q.insert({0, 1});
    vector<bool> vis(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(q.empty()) return -1;
 
        int u = q.begin()->second;
        vis[u] = 1;
        weight += q.begin()->first;
        q.erase(q.begin());
        for(auto& [neighbor, cost] : adj[u]) {
            if(!vis[neighbor] && cost < dist[neighbor]) {
                q.erase({dist[neighbor], neighbor});
				//dist[neighbor] = cost;
				q.insert({dist[neighbor] = cost, neighbor});
				//debug(dist);
				//debug(q);
            }
        }
        //debug(q);
    }
    return weight;
}
 
void solve() {
 
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    long long ans = Prim(n, adj);
    if(ans == -1) cout << "IMPOSSIBLE" << '\n';
    else cout << ans << '\n';
 
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

*/