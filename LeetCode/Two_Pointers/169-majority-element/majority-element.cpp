class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's voting algorithm
        int ans = 0, majority = 0;
        for(auto curr : nums) {
            if(majority == 0) {
                ans = curr;
            }
            majority += (curr == ans) ? 1 : -1;
        }
        return ans;
    }
};