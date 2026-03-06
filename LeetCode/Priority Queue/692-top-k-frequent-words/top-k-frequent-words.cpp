class Solution {
public:
    unordered_map<string, int> freq;
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto compare = [this](const string& l, const string& r) {
            return (freq[l] == freq[r]) ? (l < r) : (freq[l] > freq[r]);
        };
        priority_queue<string, vector<string>, decltype(compare)> pq(compare);
        for(auto u : words) {
            freq[u]++;
        }
        for(auto u : freq) {
            pq.push(u.first);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};