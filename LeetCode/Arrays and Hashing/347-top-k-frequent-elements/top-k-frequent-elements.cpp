class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(auto u : nums) {
            cnt[u]++;
        }
        int len = nums.size();
        vector<vector<int>> freqs(len + 1);
        for(auto [val, count]: cnt) {
            freqs[count].push_back(val);
        }
        vector<int> ans;
        for(int i = len; i >= 0; i--) {
            for(auto val : freqs[i]) {
                ans.push_back(val);
                if(ans.size() == k) {
                    return ans;
                }
            }   
        }
        return ans;
    }
};