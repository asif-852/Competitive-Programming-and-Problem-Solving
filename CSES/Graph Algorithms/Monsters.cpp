
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    int sr, sc;
    vector<pair<int, int>> monsters;

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                sr = i;
                sc = j;
            } else if(grid[i][j] == 'M') {
                monsters.push_back({i, j});
            }
        }
    }

    // BFS 1: Calculate minimum time for any monster to reach each cell
    vector<vector<int>> distM(n, vector<int>(m, inf));
    queue<pair<int, int>> qM;

    for(auto [r, c] : monsters) {
        distM[r][c] = 0;
        qM.push({r, c});
    }

    while(!qM.empty()) {
        auto [r, c] = qM.front();
        qM.pop();

        for(auto [dr, dc] : {pair{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int nr = r + dr;
            int nc = c + dc;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && distM[nr][nc] == inf) {
                distM[nr][nc] = distM[r][c] + 1;
                qM.push({nr, nc});
            }
        }
    }

    // BFS 2: Find path for 'A' ensuring arrival time < monster arrival time
    vector<vector<int>> distA(n, vector<int>(m, -1));
    vector<vector<char>> path(n, vector<char>(m, 0));
    
    queue<pair<int, int>> qA;
    qA.push({sr, sc});
    distA[sr][sc] = 0;

    int er = -1, ec = -1;

    while(!qA.empty()) {
        auto [r, c] = qA.front();
        qA.pop();

        // Check if we reached the boundary
        if(r == 0 || r == n - 1 || c == 0 || c == m - 1) {
            er = r;
            ec = c;
            break;
        }

        for(auto [dr, dc, dir] : {tuple{-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}}) {
            int nr = r + dr;
            int nc = c + dc;
            
            // Check bounds, walls, visited, and monster safety condition
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && distA[nr][nc] == -1) {
                if(distA[r][c] + 1 < distM[nr][nc]) {
                    distA[nr][nc] = distA[r][c] + 1;
                    path[nr][nc] = dir;
                    qA.push({nr, nc});
                }
            }
        }
    }

    if(er != -1) {
        cout << "YES" << '\n';
        cout << distA[er][ec] << '\n';
        
        string moves = "";
        int r = er;
        int c = ec;
        while(r != sr || c != sc) {
            char move = path[r][c];
            moves += move;

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