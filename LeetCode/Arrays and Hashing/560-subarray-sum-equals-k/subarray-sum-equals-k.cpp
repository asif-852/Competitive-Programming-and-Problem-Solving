class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long sum = 0, ans = 0;
        map<long long, int> cnt;
        cnt[0] = 1;
        for(auto u : nums) {
            sum += u;
            ans += cnt[sum - k];
            cnt[sum]++;
        }
        return ans;
    }
};