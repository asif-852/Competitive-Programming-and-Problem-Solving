class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& l, const vector<int>& r) {
            return l[1] < r[1];
        });
        priority_queue<int> pq;
        pq.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++) {
            if(!pq.empty() && pq.top() <= intervals[i][0]) {
                pq.push(intervals[i][1]);
            }
        }
        return intervals.size() - pq.size();
    }
};