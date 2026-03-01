class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = 2e9, ans = -1;

        for(int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if(abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    ans = sum;
                }
                (sum < target) ? l++ : r--;
            }
        }
        return ans;
    }
};