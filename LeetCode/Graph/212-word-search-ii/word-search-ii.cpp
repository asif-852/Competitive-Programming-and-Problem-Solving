class Solution {
public:
    int nxt[3 * 10000 * 10][26];
    bitset<3 * 10000 * 10> endnode, nodevis;
    int total = 1;
    map<int, string> retrieve;
    vector<string> ans;

    void add_string(string s) {
        int curr = 1;
        for(int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            if(!nxt[curr][ch]) {
                nxt[curr][ch] = ++total;
            }
            curr = nxt[curr][ch];
            if(i == s.size() - 1) {
                endnode[curr] = 1;
                retrieve[curr] = s;
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, int curr, vector<vector<bool>>& vis) {
        int rows = board.size();
        int cols = board[0].size();
        if(i < 0 || i >= rows || j < 0 || j >= cols || !nxt[curr][board[i][j] - 'a'] || vis[i][j]) {
            return;
        }
        vis[i][j] = 1;
        curr = nxt[curr][board[i][j] - 'a'];
        if(endnode[curr] && !nodevis[curr]) {
            ans.push_back(retrieve[curr]);
            nodevis[curr] = 1;
        }

        dfs(board, i + 1, j, curr, vis);
        dfs(board, i - 1, j, curr, vis);
        dfs(board, i, j + 1, curr, vis);
        dfs(board, i, j - 1, curr, vis);
        vis[i][j] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto u : words) {
            add_string(u);
        }
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vector<vector<bool>> vis(m, vector<bool>(n, false));
                dfs(board, i, j, 1, vis);
            }
        }
        return ans;
    }
};