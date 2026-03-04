class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n);
        stack<pair<int, int>> s;
        s.push({temperatures[0], 0});
        for(int i = 1; i < n; i++) {
            while(!s.empty() && s.top().first < temperatures[i]) {
                auto[_, idx] = s.top();
                s.pop();
                answer[idx] = i - idx;
            }
            s.push({temperatures[i], i});
        }
        while(!s.empty()) {
            answer[s.top().second] = 0;
            s.pop();
        }
        return answer;
    }
};