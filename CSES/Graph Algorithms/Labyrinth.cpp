#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    int sr, sc, er, ec;     // start_row, start_col, end_row, end_col

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                sr = i;
                sc = j;
            } else if(grid[i][j] == 'B') {
                er = i;
                ec = j;
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<char>> path(n, vector<char>(m, 0)); 
    
    queue<pair<int, int>> q;
    q.push({sr, sc});
    dist[sr][sc] = 0;

    bool found = false;

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if(r == er && c == ec) {
            found = true;
            break;
        }

        for(auto [dr, dc, dir] : {tuple{-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}}) {
            int nr = r + dr;
            int nc = c + dc;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                path[nr][nc] = dir;
                q.push({nr, nc});
            }
        }
    }

    if(found) {
        cout << "YES" << '\n';
        cout << dist[er][ec] << '\n';
        
        string moves = "";
        int r = er;
        int c = ec;
        while(r != sr || c != sc) {
            char move = path[r][c];
            moves += move;

            // Reverse the move to go back to the parent cell
            if(move == 'U') r++;
            else if(move == 'D') r--;
            else if(move == 'L') c++;
            else if(move == 'R') c--;
        }

        reverse(moves.begin(), moves.end());
        cout << moves << '\n';
        return;
    } 
    cout << "NO" << '\n';
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