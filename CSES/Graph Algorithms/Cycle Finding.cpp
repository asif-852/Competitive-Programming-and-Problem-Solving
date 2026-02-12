
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    //Run n-1 relaxations
    for(int i = 1; i <= n - 1; i++) {
        for(auto [u, v, w] : edges) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    //Check for negative cycle on n-th iteration
    int cycleNode = -1;
    for(auto [u, v, w] : edges) {
        if(dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            parent[v] = u;
            cycleNode = v;
        }
    }

    if(cycleNode == -1) {
        cout << "NO" << '\n';
        return;
    }

    //Go back n times to ensure we are inside the cycle
    for(int i = 0; i < n; i++) {
        cycleNode = parent[cycleNode];
    }

    vector<int> cycle;
    int curr = cycleNode;
    do {
        cycle.push_back(curr);
        curr = parent[curr];
    } while(curr != cycleNode);
    cycle.push_back(cycleNode);

    reverse(cycle.begin(), cycle.end());

    cout << "YES" << '\n';
    for(int i = 0; i < (int)cycle.size(); i++) {
        cout << cycle[i] << " \n"[i == (int)cycle.size() - 1];
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
