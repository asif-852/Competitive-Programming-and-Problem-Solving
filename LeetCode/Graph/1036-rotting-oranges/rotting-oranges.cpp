class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int total = 0;
        set<pair<int, int>> st;
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    total++;
                    q.push({i, j, 0});
                } else if(grid[i][j] == 1) {
                    total++;
                }
            }
        }
        if(total == 0) {
            return 0;
        }
        while(!q.empty()) {
            auto [r, c, time] = q.front();
            st.insert({r, c});
            q.pop();
            
            if(st.size() == total) {
                return time;
            }
            for(auto &[dr, dc] : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                int new_r = r + dr, new_c = c + dc;
                if(min(new_r, new_c) >= 0 && new_r < m && new_c < n && grid[new_r][new_c] == 1) {
                    grid[new_r][new_c] = 2;
                    q.push({new_r, new_c, time + 1});
                }
            }
        }
        return -1;
    }
};