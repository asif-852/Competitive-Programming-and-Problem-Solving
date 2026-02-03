

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, componentSize, edges;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        componentSize.assign(n + 1, 1);
        edges.assign(n + 1, 0);
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            edges[x]++;
            return false;
        }
        componentSize[x] += componentSize[y];
        edges[x]++;
        edges[x] += edges[y];
        parent[y] = x;
        return true;
    }

    int size(int x) {
        return componentSize[find(x)];
    }

    void reset(int x) {
        parent[x] = x;
        componentSize[x] = 1;
    }
};


void solve() {

    DSU d(1100);
    map<int, bool> vis;
    vector<int> nodes;
    int u, v;
    while(cin >> u >> v) {
        d.merge(u, v);
        nodes.push_back(u);
        nodes.push_back(v);
    }

    bool ok = 1;
    for(auto u : nodes) {
        int leader = d.find(u);
        if(!vis[leader]) {
            if(d.edges[leader] % 2 != 0) {
                ok = 0;
            }
            vis[leader] = 1;
        }
    }
    cout << ok << '\n';

}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}