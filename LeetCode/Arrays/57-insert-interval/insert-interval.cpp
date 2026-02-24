class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int pos = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        intervals.insert(intervals.begin() + pos, newInterval);
        int n = intervals.size();
        int start = -1, end = -1;
        vector<int> merged(2);
        for(int i = 0; i + 1 < n; i++) {
            if(intervals[i][1] >= intervals[i + 1][0]) {
                merged[0] = min(intervals[i][0], intervals[i + 1][0]);
                merged[1] = max(intervals[i][1], intervals[i + 1][1]);
                start = i;
                break;
            }
        }
        if(start == -1) {
            return intervals;
        }
        for(int i = start; i < n; i++) {
            if(merged[1] < intervals[i][0]) {
                break;
            }
            merged[1] = max(merged[1], intervals[i][1]);
            end = i;
        }
        vector<vector<int>> ans;
        for(int i = 0; i < start; i++) {
            ans.push_back(intervals[i]);
        }
        ans.push_back(merged);
        for(int i = end + 1; i < n; i++) {
            ans.push_back(intervals[i]);
        }
        return ans; 
    }
};