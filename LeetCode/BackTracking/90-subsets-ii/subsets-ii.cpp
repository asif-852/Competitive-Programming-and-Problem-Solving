

// Approach 2: Using Bitmasking and data structures



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

