
#include <bits/stdc++.h>
using namespace std;

struct Point{
    long double x, y;

    bool operator<(const Point other) const {
        return (y < other.y) || (y == other.y && x < other.x);
    }
};

Point pivot;
vector<Point> ans;

long double Distance(const Point p1, const Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

long double orientation(const Point ref, const Point a, const Point b) {
    long double val = (a.x - ref.x) * (b.y - ref.y) - (b.x - ref.x) * (a.y - ref.y);
    if(val == 0) return 0;     //Collinear
    return (val < 0) ? 1 : 2;  //1 for Clockwise, 2 for Counterclockwise
}

void GrahamScan(vector<Point>& v) {
    int n = v.size();
    if(n < 3) return;

    swap(*min_element(v.begin(), v.end()), v[0]);

    pivot = v[0];
    sort(v.begin() + 1, v.end(), [&](const Point a, const Point b) {
        long double ans = orientation(pivot, a, b);
        return (ans == 0) ? Distance(pivot, b) >= Distance(pivot, a) : ans == 2;
    });


    ans.push_back(v[0]);
    ans.push_back(v[1]);
    for(int i = 2; i < n; i++) {
        while(ans.size() > 2 && orientation(ans[ans.size() - 2], ans.back(), v[i]) != 2) {
            ans.pop_back();
        }
        ans.push_back(v[i]);
    }

//    for(auto u : ans) {
//        cout << u.x << " " << u.y << '\n';
//    }

}

void solve() {

    int n, l;
    cin >> n >> l;
    vector<Point> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }

    GrahamScan(v);

    ans.push_back(v[0]);
    long double res = 0;
    for(int i = 0; i < ans.size() - 1; i++) {
        //debug(Distance(ans[i], ans[i + 1]));
        res += Distance(ans[i], ans[i + 1]);
        //debug(res);
    }
    cout << round(res + 2 * acos(-1) * l) << '\n';

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