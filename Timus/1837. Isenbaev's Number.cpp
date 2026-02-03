
#include <bits/stdc++.h>
using namespace std;
 
void BFS(string src, map<string, vector<string>> &adj, map<string, int> &level) {
    queue<string> q;
    q.push(src);
    level[src] = 0;

    while(!q.empty()) {
        string u = q.front();
        q.pop();

        for(auto v : adj[u]) {
            if(level[v] == 1e9) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    map<string, vector<string>> adj;
    map<string, int> level;
    bool exist = 0;
    while(n--) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        if(s1 == "Isenbaev" || s2 == "Isenbaev" || s3 == "Isenbaev" ) exist = 1;

        level[s1] = 1e9;
        level[s2] = 1e9;
        level[s3] = 1e9;

        adj[s1].push_back(s2);
        adj[s2].push_back(s1);
        adj[s1].push_back(s3);
        adj[s3].push_back(s1);
        adj[s2].push_back(s3);
        adj[s3].push_back(s2);
    }

    BFS("Isenbaev", adj, level);

    //debug(level);

    if(!exist) {
        for(auto [name, dist] : level) {
            if(name == "Isenbaev") continue;
            cout << name << " undefined" << '\n';
        }
        return;
    }

    for(auto [name, dist] : level) {
        if(dist == 1e9) {
            cout << name << " undefined" << '\n';
        } else {
            cout << name << " " << dist << '\n';
        }
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