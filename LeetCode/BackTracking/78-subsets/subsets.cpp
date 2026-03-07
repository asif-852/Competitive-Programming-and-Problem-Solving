class Solution {
public:
    void backtrack(const vector<int>& nums, int start, vector<int>& current_subset, vector<vector<int>>& result) {
        result.push_back(current_subset);
        
        for(int i = start; i < nums.size(); i++) {
            current_subset.push_back(nums[i]);
            backtrack(nums, i + 1, current_subset, result);  // passing 'i + 1' to only consider numbers AFTER the current one, preventing duplicates like [1, 2] & [2, 1]
            current_subset.pop_back();  // Un-choose (Backtrack): Remove the number to try the next one in the loop
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current_subset;
        backtrack(nums, 0, current_subset, result);
        return result;
    }
};


// Approach 2: Bitmasking

/*

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int mask = 0; mask < (1 << n); mask++) {
            vector<int> temp;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

*/