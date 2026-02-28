// Approach 1: Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};


// Approach 2: Time Complexity: O(NlogN), Space Complexity: O(1)
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;        
    }
};
*/