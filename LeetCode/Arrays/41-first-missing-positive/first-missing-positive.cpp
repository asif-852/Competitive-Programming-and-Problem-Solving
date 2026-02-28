class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] < 1 || nums[i] > n) {
                nums[i] = -1e9;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] >= 1 && nums[i] <= n) {
                while(nums[nums[i] - 1] != nums[i]) {
                    swap(nums[nums[i] - 1], nums[i]);
                    if(nums[i] == -1e9) break;
                }
            }
        }
        
        for(int i = 1; i <= n; i++) {
            if(nums[i - 1] != i) {
                return i;
            }
        }
        return n + 1;
    }
};