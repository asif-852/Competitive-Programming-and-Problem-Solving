class Solution {
public:
    int n;
    vector<string> board;
    unordered_map<int, bool> colvis, negDiagonal, posDiagonal;
    vector<vector<string>> ans;
    void backtrack(int row) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++) {
            if(!colvis[col] && !negDiagonal[row - col] && !posDiagonal[row + col]) {
                board[row][col] = 'Q';
                colvis[col] = 1;
                negDiagonal[row - col] = 1;
                posDiagonal[row + col] = 1;
                backtrack(row + 1);
                board[row][col] = '.';
                colvis[col] = 0;
                negDiagonal[row - col] = 0;
                posDiagonal[row + col] = 0;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board.assign(n, string(n, '.'));
        backtrack(0);
        return ans;
    }
};