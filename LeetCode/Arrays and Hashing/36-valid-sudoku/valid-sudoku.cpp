class Solution {
public:
    bool isValid(int row, int col, char c, vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == c) {
                return false;
            }
            if(board[i][col] == c) {
                return false;
            }
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char temp = board[i][j];
                if(temp == '.') {
                    continue;
                }
                board[i][j] = '!';
                if(!isValid(i, j, temp, board)) {
                    return false;
                }
                board[i][j] = temp;
            }
        }
        return true;
    }
};