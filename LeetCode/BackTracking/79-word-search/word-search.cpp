class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, const string& word, int curr_depth) {
        if(curr_depth == word.size()) {
            return true;
        }
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[curr_depth]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';
        
        bool found = false;
        const array<pair<int, int>, 4> dirs = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
        for(auto& [di, dj] : dirs) {
            if(dfs(board, i + di, j + dj, word, curr_depth + 1)) {
                found = true;
                break;
            }
        }

        board[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, i, j, word, 0)) {
                        return true; 
                    }
                }
            }
        }
        return false;
    }
};