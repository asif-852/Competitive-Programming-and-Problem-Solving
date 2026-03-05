class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int ans = 2e9;
        while(l <= r) {
            int mid = (l + r) / 2;
            ans = min(ans, nums[mid]);
            if(nums[l] <= nums[mid]) {
                // Left portion is evidently sorted
                ans = min(ans, nums[l]);
                l = mid + 1;
            } else {
                // Right portion is evidently sorted
                ans = min(ans, nums[mid]);
                r = mid - 1;
            }
        }
        return ans;
    }
};
