
// Approach 1: Tree re-rooting


#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> first_max, second_max;
vector<vector<int>> adj;
 
void dfs(int node, int par) {
    for(auto child : adj[node]) {
        if(child ^ par) {
            dfs(child, node);
            if(first_max[child] + 1 > first_max[node]) {
                second_max[node] = first_max[node];
                first_max[node] = first_max[child] + 1;
            } else if(first_max[child] + 1 > second_max[node]) {
                second_max[node] = first_max[child] + 1;
            }
        }
    }
}
 
void re_root(int node, int par) {
    for(auto child : adj[node]) {
        if(child ^ par) {
            // Child will be the new root
            if(first_max[node] == first_max[child] + 1) {
                // this child was the maximum value yielding child
                if(second_max[node] + 1 > first_max[child]) {
                    second_max[child] = first_max[child];
                    first_max[child] = second_max[node] + 1;
                } else {
                    second_max[child] = max(second_max[child], second_max[node] + 1);
                }
            } else {
                second_max[child] = first_max[child];
                first_max[child] = first_max[node] + 1;
            }
 
            re_root(child, node);
        }
    }
}

 
void solve() {
 
    cin >> n;
    adj.resize(n);
    first_max.resize(n);
    second_max.resize(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    //Calculating answer for the first root
    dfs(0, -1);
 
    //Calculating answer for other roots
    re_root(0, -1);
 
    for(int i = 0; i < n; i++) {
        cout << first_max[i] << " \n"[i == n - 1];
    }
 
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
 












// Approach 2: BFS

/*
#include <bits/stdc++.h>
using namespace std;
 
vector<int> ans(2e5 + 1, 0);
 
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
                ans[v] = max(ans[v], level[v]);
                q.push(v);
            }
        }
    }
}
 
void solve() {
 
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<int> level(n + 1, 1e9);
    BFS(1, adj, level);
    int end1 = max_element(level.begin() + 1, level.end()) - level.begin();
    level.assign(n + 1, 1e9);
    BFS(end1, adj, level);
    int end2 = max_element(level.begin() + 1, level.end()) - level.begin();
    //debug(end1, end2);
 
    level.assign(n + 1, 1e9);
    BFS(end1, adj, level);
    level.assign(n + 1, 1e9);
    BFS(end2, adj, level);
 
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
 
    return 0;
}

*/
