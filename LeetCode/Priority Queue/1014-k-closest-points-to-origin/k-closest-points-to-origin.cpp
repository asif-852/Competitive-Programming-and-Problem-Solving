class Solution {
public:
    struct Point{
        int x, y;
    };
    static int distance(Point p) {
        return p.x * p.x + p.y * p.y;
    } 
    struct Compare {
        bool operator()(const Point& l, const Point& r) const {
            return distance(l) < distance(r);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point, vector<Point>, Compare> pq;
        for(auto u : points) {
            Point p = {u[0], u[1]};
            pq.push(p);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.push_back({x, y});
        }
        return ans;
    }
};
