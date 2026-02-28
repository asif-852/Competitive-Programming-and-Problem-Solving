class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 0, j = 1; j < prices.size();) {
            while(j < prices.size() && prices[j] - prices[i] >= 0) {
                ans = max(ans, prices[j] - prices[i]);
                j++;
            }
            i = j;
        }
        return ans;
    }
};