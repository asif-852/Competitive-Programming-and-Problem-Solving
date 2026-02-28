class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& l, const vector<int>& r){
            return l[0] < r[0];
        });
        vector<vector<int>> ans;
        int n = intervals.size(), start = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                ans.push_back(vector<int> {start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back(vector<int> {start, end});
        return ans;
    }
};