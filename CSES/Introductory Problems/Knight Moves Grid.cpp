#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<vector<int>> dist;
 
void calc() {
    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});
 
    while(!q.empty()) {
        auto [currx, curry] = q.front();
        q.pop();
 
        for(auto [dx, dy] : vector<pair<int, int>> {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}}) {
            int nx = currx + dx;
            int ny = curry + dy;
 
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[currx][curry] + 1;
                q.push({nx, ny});
            }
        }
    }
}
 
void solve() {
 
    cin >> n;
    dist.assign(n, vector<int>(n, -1));
    calc();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << dist[i][j] << " \n"[j == n - 1];
        }
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
