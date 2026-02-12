
#include <bits/stdc++.h>
using namespace std;

struct LCA {
    int n, LOG;
    vector<vector<int>> adj;
    vector<vector<int>> up; // up[v][i] stores the 2^i-th ancestor of v
    vector<int> depth, sub_size;

    LCA(int _n) : n(_n) {
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        
        adj.assign(n + 1, vector<int>());
        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);
        sub_size.assign(n + 1, 0);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build(int root = 1) {
        dfs(root, 0);
    }

    void dfs(int u, int p) {
        depth[u] = depth[p] + 1;
        sub_size[u] = 1;
        up[u][0] = p;

        for (int i = 1; i < LOG; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u);
                sub_size[u] += sub_size[v];
            }
        }
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        // Lift u to the same depth as v
        for (int i = LOG - 1; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        // Lift both until they are just below the LCA
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    int kth_ancestor(int u, int k) {
        for (int i = 0; i < LOG; i++) {
            if ((k >> i) & 1) {
                u = up[u][i];
            }
        }
        return u;
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
    }

    // Returns the k-th node on the simple path from u to v (0-indexed)
    // k=0 returns u, k=dist(u,v) returns v
    int kth_node_on_path(int u, int v, int k) {
        int l = get_lca(u, v);
        int d_u = depth[u] - depth[l];
        int d_v = depth[v] - depth[l];
        
        assert(k <= d_u + d_v); // Safety check

        if (k <= d_u) {
            return kth_ancestor(u, k);
        } else {
            // The node is on the v side, we need to backtrack from v
            // Distance from v is (total_dist - k)
            return kth_ancestor(v, (d_u + d_v) - k);
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    LCA lca(n);
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        lca.add_edge(i, p);
    }
    lca.build(1);
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << lca.get_lca(a, b) << '\n';
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