class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> exist;
        for(auto u : nums) {
            exist[u] = 1;
        }
        int ans = 0;
        unordered_map<int, bool> vis;
        for(auto u : nums) {
            if(!vis[u]) {
                int len = 1;
                vis[u] = 1;
                int temp = u;
                while(exist[u - 1] && !vis[u - 1]) {
                    len++;
                    u--;
                    vis[u] = 1;
                }
                u = temp;
                while(exist[u + 1] && !vis[u + 1]) {
                    len++;
                    u++;
                    vis[u] = 1;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};