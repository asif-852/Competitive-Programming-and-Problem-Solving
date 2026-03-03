class Solution {
public:
    long long time(long long k, vector<int>& piles) {
        long long res = 0;
        for(auto u : piles) {
            res += (u + k - 1) / k;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long lo = 1, hi = *max_element(piles.begin(), piles.end());
        long long ans;
        while(lo <= hi) {
            long long mid = (lo + hi) >> 1;
            long long t = time(mid, piles);
            (t <= h) ? hi = mid - 1, ans = mid : lo = mid + 1;
        }
        return ans;
    }
};