class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int l = nums[0][0], r = l;
        vector<int> ans;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        for(int i = 0; i < k; i++) {
            l = min(l, nums[i][0]);
            r = max(r, nums[i][0]);
            pq.push({nums[i][0], i, 0});
        }
        ans = {l, r};
        while(1) {
            auto [_, i, idx] = pq.top();
            pq.pop();
            if(++idx == nums[i].size()) {
                break;
            }
            int nextVal = nums[i][idx];
            pq.push({nextVal, i, idx});
            r = max(r, nextVal);
            l = pq.top()[0];
            if(r - l < ans[1] - ans[0]) {
                ans[0] = l;
                ans[1] = r;
            }
        }
        return ans;
    }
};