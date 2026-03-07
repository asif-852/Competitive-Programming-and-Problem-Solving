class Solution {
public:
    void backtrack(const vector<int>& nums, vector<int>& curr_path, bitset<6>& used, vector<vector<int>>& result) {
        if(curr_path.size() == nums.size()) {
            result.push_back(curr_path);
            return;
        }
        // Iterate through all possible candidates
        for(int i = 0; i < nums.size(); i++) {
            if(used[i]) {
                continue;
            }
            used[i] = 1;
            curr_path.push_back(nums[i]);
            backtrack(nums, curr_path, used, result);   // Recurse with the updated path
            
            // Un-choose (Backtrack): Remove from path and mark as unused
            curr_path.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr_path; 
        bitset<6> used;
        backtrack(nums, curr_path, used, result);
        return result;
    }
};

// Approach 2: Modifying the original array

/*

class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        if(start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};

*/