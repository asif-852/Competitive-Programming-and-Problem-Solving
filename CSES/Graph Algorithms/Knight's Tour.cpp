
#include <bits/stdc++.h>
using namespace std;
 
int board[8][8];

int futureMoves(int r, int c) {
    int count = 0;
    for(auto [dr, dc] : vector<pair<int, int>> {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}}) {
        int nr = r + dr;
        int nc = c + dc;
        count += (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && board[nr][nc] == 0);
    }
    return count;
}
 
bool solveKnightTour(int r, int c, int count) {
    board[r][c] = count;
 
    if(count == 64) {
        return true;
    }
 
    vector<pair<int, pair<int, int>>> moves;
    for(auto [dr, dc] : vector<pair<int, int>> {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}}) {
        int nr = r + dr;
        int nc = c + dc;
        if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && board[nr][nc] == 0) {
            moves.push_back({futureMoves(nr, nc), {nr, nc}});
        }
    }
 
    sort(moves.begin(), moves.end());
 
    for(auto& [val, move] : moves) {
        auto& [r, c] = move;
        if(solveKnightTour(r, c, count + 1)) {
            return true;
        }
    }
 
    board[r][c] = 0;
    return false;
 
}
 
void solve() {
 
    int r, c;
    cin >> c >> r;
    --r, --c;
    solveKnightTour(r, c, 1);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << board[i][j] << " \n"[j == 7];
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
