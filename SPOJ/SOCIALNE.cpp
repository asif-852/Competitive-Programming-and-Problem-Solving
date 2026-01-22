
#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> v(n);
    for(int i = 0; i < n; i++) {
        if(i == 0) v[i] = s;
        else cin >> v[i];
    }
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = (v[i][j] == 'Y') ? 1 : 0;
        }
    }
    //debug(matrix);
    vector<vector<int>> sqmatrix(n, vector<int>(n));
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            for(int ele = 0; ele < n; ele++) {
                sqmatrix[row][col] += matrix[row][ele] * matrix[ele][col];
            }
        }
    }
    //debug(sqmatrix);
    vector<int> friends(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            friends[i] += (j != i && sqmatrix[i][j] && !matrix[i][j]);
        }
    }
    int ans = -1, mx = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(friends[i] >= mx) {
            mx = friends[i];
            ans = i;
        }
    }
    cout << ans << " " << friends[ans] << '\n';
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
 
    return 0;
} 