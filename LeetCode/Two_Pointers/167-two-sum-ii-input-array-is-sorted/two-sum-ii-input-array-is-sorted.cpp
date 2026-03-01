class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        vector<int> ans;
        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if(sum == target) {
                ans = {l + 1, r + 1};
                break;
            }
            (sum < target ? l++ : r--);
        }
        return ans;
    }
};