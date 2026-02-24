class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        auto compare = [](const pair<int, int>& l, const pair<int, int>& r) {
            return (l.second - l.first) > (r.second - r.first);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        for(int i = 0; i < intervals.size(); i++) {
            pq.push({intervals[i][0], intervals[i][1]});
        }
        map<int, vector<int>> idx;
        for(int i = 0; i < queries.size(); i++) {
            idx[queries[i]].push_back(i);
        }
        vector<int> ans(queries.size());
        while(!pq.empty()) {
            auto [low, high] = pq.top();
            pq.pop();
            auto itLow = idx.lower_bound(low);
            auto itHigh = idx.upper_bound(high);
            for(auto it = itLow; it != itHigh; it++) {
                while(!it->second.empty()) {
                    ans[it->second.back()] = high - low + 1;
                    it->second.pop_back();
                }
            }
            idx.erase(itLow, itHigh);
        }
        for(auto& u: ans) {
            if(u == 0) {
                u = -1;
            }
        }
        return ans;
    }
};