
#include <bits/stdc++.h>
using namespace std;
 
const int M = 11;
 
vector<vector<int>> parent;
vector<int> depth;
vector<vector<int>> tree;
 
void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node][0] = par;
    for(int i = 1; i < M; i++) {
        if(parent[node][i - 1] != -1) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        }
        else break;
    }
 
    for(auto child : tree[node]) {
        dfs(child, node, d + 1);
    }
}
 
int lca(int u, int v) {
    if(u == v) return u;
 
    if(depth[u] < depth[v]) swap(u, v);
 
    int diff = depth[u] - depth[v];
    for(int i = 0; i < M; i++) {
        if ((1 << i) & diff) u = parent[u][i];
    }
 
    if(u == v) return u;
 
    for(int i = M - 1; i >= 0; i--) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
 
    return parent[u][0];
}
 
void solve() {
 
    int n;
    cin >> n;
    parent.resize(n + 1, vector<int>(M, -1));
    depth.resize(n + 1);
    tree.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        int no;
        cin >> no;
        while(no--) {
            int child;
            cin >> child;
            tree[i].push_back(child);
        }
    }
    dfs(1, -1, 0);
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        parent.clear();
        depth.clear();
        tree.clear();
        cout << "Case " << i << ":\n";
        solve();
    }
 
    return 0;
} 