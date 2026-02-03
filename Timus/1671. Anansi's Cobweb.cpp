
// author: Rohanbiswas
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
        while(x != parent[x]) {
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
        if(x == y) {
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



void solve() {

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    DSU dsu(n);
    int cnt = n;
    int q;
    cin >> q;
    vector<int> queries;
    vector<bool> removed(m, 0);
    for(int i = 0; i < q; i++) {
        int idx;
        cin >> idx;
        queries.push_back(idx - 1);
        removed[idx - 1] = 1;
    }
    for(int i = 0; i < m; i++) {
        if(!removed[i]) {
            if(dsu.merge(edges[i].first, edges[i].second)) --cnt;
        }
    }
    vector<int> ans = {cnt};
    for(int i = q - 1; i > 0; i--) {
        int u = edges[queries[i]].first;
        int v = edges[queries[i]].second;
        if(dsu.merge(u, v)) --cnt;
        ans.push_back(cnt);
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " \n"[i == (int)ans.size() - 1];
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