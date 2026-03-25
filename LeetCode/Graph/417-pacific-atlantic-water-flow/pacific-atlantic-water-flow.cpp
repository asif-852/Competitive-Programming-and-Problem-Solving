class Solution {
public:
    int Rows, Cols; 
    void bfs(int r, int c, vector<bitset<200>>& reachable, vector<vector<int>>& heights) {
        if(reachable[r][c]) {
            return;
        }
        queue<pair<int, int>> q;
        q.push({r, c});
        reachable[r][c] = 1;

        while(!q.empty()) {
            auto [curr_r, curr_c] = q.front();
            q.pop();

            static const array<pair<int, int>, 4> dirs = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
            for(auto& [dr, dc] : dirs) {
                int nr = curr_r + dr, nc = curr_c + dc;
                if(!(nr < 0 || nr >= Rows || nc < 0 || nc >= Cols) && !reachable[nr][nc] && heights[nr][nc] >= heights[curr_r][curr_c]) {
                    reachable[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        Rows = heights.size();
        Cols = heights[0].size();

        vector<bitset<200>> pacific_reachable(200);
        vector<bitset<200>> atlantic_reachable(200);

        // BFS from Top Row
        for(int c = 0; c < Cols; c++) {
            bfs(0, c, pacific_reachable, heights);
        }
        // BFS from Left Column
        for(int r = 0; r < Rows; r++) {
            bfs(r, 0, pacific_reachable, heights);
        }

        // BFS from Bottom Row
        for(int c = 0; c < Cols; c++) {
            bfs(Rows - 1, c, atlantic_reachable, heights);
        }
        // BFS from Right Column
        for(int r = 0; r < Rows; r++) {
            bfs(r, Cols - 1, atlantic_reachable, heights);
        }

        vector<vector<int>> result;
        for(int r = 0; r < Rows; r++) {
            for(int c = 0; c < Cols; c++) {
                if(pacific_reachable[r][c] && atlantic_reachable[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};