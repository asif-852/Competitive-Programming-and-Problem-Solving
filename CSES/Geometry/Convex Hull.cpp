
#include <bits/stdc++.h>
using namespace std;
 
struct Point{
    long long x, y;
};
 
int orientation(const Point ref, const Point a, const Point b) {
    long long val = (a.x - ref.x) * (b.y - ref.y) - (b.x - ref.x) * (a.y - ref.y);
    if(val == 0) return 0;     //Collinear
    return (val < 0) ? 1 : 2;  //1 for Clockwise, 2 for Counterclockwise
}
 
vector<Point> GrahamScan(vector<Point>& v) {
    int n = v.size();
 
    vector<Point> ans;
    ans.push_back(v[0]);
    ans.push_back(v[1]);
    for(int i = 2; i < n; i++) {
        while(ans.size() > 1 && orientation(ans[ans.size() - 2], ans.back(), v[i]) == 1) {
            ans.pop_back();
        }
        ans.push_back(v[i]);
        //debug(ans.back().x, ans.back().y);
    }
    return ans;
}
 
void solve() {
 
    int n;
    cin >> n;
    vector<Point> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    sort(v.begin(), v.end(), [&](const Point l, const Point r) {
        return (l.x == r.x) ? (l.y < r.y) : (l.x < r.x);
    });
    vector<Point> v1 = GrahamScan(v);
//    cout << "v1: " << v1.size() << '\n';
//    for(auto u : v1) {
//        cout << u.x << " " << u.y << '\n';
//    }
 
    sort(v.begin(), v.end(), [&](const Point l, const Point r) {
        return (l.x == r.x) ? (l.y > r.y) : (l.x > r.x);
    });
    vector<Point> v2 = GrahamScan(v);
//    cout << "v2: " << v2.size() << '\n';
//    for(auto u : v2) {
//        cout << u.x << " " << u.y << '\n';
//    }
 
 
    for(int i = 1; i < v2.size(); i++) {
        if(v2[i].x == v1[0].x && v2[i].y == v1[0].y) break;
        v1.push_back(v2[i]);
    }
    cout << v1.size() << '\n';
    for(auto u : v1) {
        cout << u.x << " " << u.y << '\n';
    }
 
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
 
    return 0;
}
