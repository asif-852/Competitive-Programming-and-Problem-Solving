// Approach 1: Time Complexity: O(N), Space Complexity: O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.begin(), nums.end());
    }
};

// Approach 2: Time Complexity: O(N), Space Complexity: O(N)
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[(i + k) % n] = nums[i];
        }
        nums = ans;
    }
};
*/