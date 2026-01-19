
#include <bits/stdc++.h>
using namespace std;
 
/**
 
 * Description: Kosaraju's Algorithm, DFS twice to generate
 * strongly connected components in topological order.
 * in same component if both a to b and b to a exist.
 * Time Complexity: O(N + M)
 
**/
 
 
struct SCC {
	int N;
	vector<vector<int>> adj, rev_adj;
	vector<int> todo, comp, comps;
	vector<bool> vis;
	void init(int _N) {
		N = _N;
		adj.resize(N);
		rev_adj.resize(N);
		comp = vector<int>(N, -1);
		vis.resize(N);
	}
	void add_edge(int x, int y) {
	    adj[x].push_back(y);
	    rev_adj[y].push_back(x);
    }
	void dfs(int x) {
		vis[x] = 1;
		for(int y : adj[x]) {
			if(!vis[y]) dfs(y);
		}
		todo.push_back(x);
	}
	void dfs2(int x, int v) {
		comp[x] = v;
		for(int y : rev_adj[x]) {
			if(comp[y] == -1) dfs2(y, v);
		}
	}
	void gen() {
		for(int i = 0; i < N; i++) {
			if(!vis[i]) dfs(i);
		}
		reverse(todo.begin(), todo.end());
		for(int x : todo) {
			if(comp[x] == -1) {
			    dfs2(x, x);
                comps.push_back(x);
            }
		}
	}
 
};
 
 
void solve() {
 
    int n, m;
    cin >> n >> m;
    SCC graph;
    graph.init(n);
    while(m--) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(--u, --v);
    }
    graph.gen();
 
    cout << graph.comps.size() << '\n';
    vector<int> vis(n), ans(n);
    int label = 1;
    for(int i = 0; i < n; i++) {
        (!vis[graph.comp[i]]) ? ans[i] = vis[graph.comp[i]] = label++ : ans[i] = vis[graph.comp[i]];
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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
