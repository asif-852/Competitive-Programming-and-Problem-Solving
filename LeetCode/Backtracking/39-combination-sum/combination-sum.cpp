class Solution {
public:
    void backtrack(vector<int>& candidates, int remaining_target, int start, 
                   vector<int>& current_combination, vector<vector<int>>& result) {
        if(remaining_target == 0) {
            result.push_back(current_combination);
            return;
        }
        
        if(remaining_target < 0) {
            return;
        }
        
        for(int i = start; i < candidates.size(); i++) {
            current_combination.push_back(candidates[i]);
            backtrack(candidates, remaining_target - candidates[i], i, current_combination, result);
            current_combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current_combination;
        backtrack(candidates, target, 0, current_combination, result);
        return result;
    }
};