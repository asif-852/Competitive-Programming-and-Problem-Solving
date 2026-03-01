class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), x = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if(sum == x) {
                    ans.insert({nums[i], nums[l], nums[r]});
                    l++, r--;
                } else {
                    (sum < x) ? l++ : r--;
                }
            }
        }

        vector<vector<int>> ret;
        for(auto triplets : ans) {
            ret.push_back(triplets);
        }

        return ret;
    }
};