
#include <bits/stdc++.h>
using namespace std;


struct Point {
    long long x, y, id;
};

bool comparePoints(const Point& a, const Point& b, const Point& ref) {
    long long vec1x = a.x - ref.x;
    long long vec1y = a.y - ref.y;
    long long vec2x = b.x - ref.x;
    long long vec2y = b.y - ref.y;

    return (vec1x * vec2y - vec2x * vec1y) > 0;
}

void solve() {

    int n;
    cin >> n;
    vector<Point> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].id = i + 1;
    }

    auto minPoint = min_element(v.begin(), v.end(), [](const Point& a, const Point& b) {
        return (a.x != b.x) ? (a.x < b.x) : (a.y < b.y);
    });

    swap(v[0], *minPoint);

    // Sorting the v counterclockwise around the reference point v[0]
    sort(v.begin() + 1, v.end(), [&v](const Point& a, const Point& b) {
        return comparePoints(a, b, v[0]);
    });

    cout << v[0].id << " " << v[n / 2].id << '\n';

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