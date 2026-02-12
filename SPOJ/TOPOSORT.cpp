
#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<int> indegree, ans;
 
void toposort(int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
 
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) pq.push(i);
    }
 
    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
 
        for(auto v : adj[u]) {
            if(--indegree[v] == 0) {
                pq.push(v);
            }
        }
    }
}
 
void solve() {
 
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    indegree.resize(n + 1);
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    toposort(n);
 
    if(ans.size() != n) {
        cout << "Sandro fails." << '\n';
        return;
    }
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