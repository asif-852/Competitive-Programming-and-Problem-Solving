
#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[100005];
bool vis[100005];
 
void dfs(int node) {
    if(vis[node]) return;
 
    vis[node] = true;
    for(auto neighbour : adj[node]) {
        dfs(neighbour);
    }
}
 
vector<int> get_required_cities (int nodes) {
    vector<int> v;
    for(int i = 1; i <= nodes; i++) {
        if(vis[i]) continue;
        else v.push_back(i);
        dfs(i);
    }
 
    return v;
}


void solve() {
    int n, m;
    cin >> n >> m;
 
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<int> cities = get_required_cities(n);
 
    cout << cities.size() - 1 << '\n';
    for(int i = 0; i < cities.size() - 1; i++) {
        cout << cities[i] << " " << cities[i + 1] << '\n';
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