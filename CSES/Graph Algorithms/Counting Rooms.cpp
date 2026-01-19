
#include <bits/stdc++.h>
using namespace std;
 
void dfs(vector<vector<int>>& matrix, int i, int j) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    if(i < 0 || i >= rows || j < 0 || j >= cols || matrix[i][j] != 1) {
        return;
    }
    matrix[i][j] = -1;
    dfs(matrix, i + 1, j);
    dfs(matrix, i - 1, j);
    dfs(matrix, i, j + 1);
    dfs(matrix, i, j - 1);
}
 
int count_islands(vector<vector<int>>& matrix) {
    if(matrix.empty()) {
        return 0;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    int count = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 1) {
                dfs(matrix, i, j);
                count++;
            }
        }
    }
    return count;
}


void solve() {
    int n, m;
    cin >> n >> m;
    string input_str = "";
    for(int i = 0; i < n; i++) {
        string row_str;
        cin >> row_str;
        input_str += row_str;
    }
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(input_str[i*m + j] == '.') {
                matrix[i][j] = 1;
            }
            else {
                matrix[i][j] = 0;
            }
        }
    }
    int count = count_islands(matrix);
    cout << count << '\n';

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