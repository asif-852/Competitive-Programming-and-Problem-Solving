
class Solution {
public:
    void backtrack(const vector<int>& nums, int start, vector<int>& current_subset, vector<vector<int>>& result) {
        result.push_back(current_subset);
        
        for(int i = start; i < nums.size(); i++) {
            // Skip duplicates: If the current number is the same as the previous one
            if(i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            current_subset.push_back(nums[i]);
            backtrack(nums, i + 1, current_subset, result);
            current_subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current_subset;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, current_subset, result);
        return result;
    }
};

// Approach 2: Using Bitmasking

/*

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int total_subsets = 1 << n;
        vector<vector<int>> ans;
        for(int mask = 0; mask < total_subsets; mask++) {
            vector<int> curr;
            bool is_duplicate = false;
            
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) { 
                    // If this is a duplicate number AND the previous identical number was NOT picked (bit is 0)
                    // then this configuration will result in a duplicate subset.
                    if(i > 0 && nums[i] == nums[i - 1] && (mask & (1 << (i - 1))) == 0) {
                        is_duplicate = true;
                        break; 
                    }
                    curr.push_back(nums[i]);
                }
            }
            if(!is_duplicate) {
                ans.push_back(curr);
            }
        }
        
        return ans;
    }
};

*/