class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pref_max = height, suff_max = height;
        partial_sum(pref_max.begin(), pref_max.end(), pref_max.begin(), [](int a, int b) {
            return max(a, b);
        });
        partial_sum(suff_max.rbegin(), suff_max.rend(), suff_max.rbegin(), [](int a, int b) {
            return max(a, b);
        });
        int ans = 0;
        for(int i = 0; i < height.size(); i++) {
            ans += min(pref_max[i], suff_max[i]) - height[i];
        }
        return ans;
    }
};