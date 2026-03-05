class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        for(auto& u : arr) {
            pq.push({abs(u - x), u});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            auto [_, val] = pq.top();
            pq.pop();
            ans.push_back(val);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};