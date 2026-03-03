class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(target == nums[mid]) {
                ans = mid;
                break;
            }
            (target < nums[mid]) ? r = mid - 1 : l = mid + 1;
        }
        return ans;
    }
};