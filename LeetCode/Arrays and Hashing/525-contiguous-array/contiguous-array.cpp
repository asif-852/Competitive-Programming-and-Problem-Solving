class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> idx;
        idx[0] = -1;
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] ? 1 : -1);
            if(idx.count(sum)) {
                ans = max(ans, i - idx[sum]);
            } else {
                idx[sum] = i;
            }
        }
        return ans;
    }
};