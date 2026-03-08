class Solution {
public:
    void backtrack(vector<int>& candidates, int remaining_target, int start, 
                   vector<int>& current_combination, vector<vector<int>>& result) {
        if(remaining_target == 0) {
            result.push_back(current_combination);
            return;
        }
        
        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if(candidates[i] > remaining_target) {
                break;
            }
            current_combination.push_back(candidates[i]);
            backtrack(candidates, remaining_target - candidates[i], i + 1, current_combination, result);
            current_combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current_combination;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current_combination, result);
        return result;
    }
};