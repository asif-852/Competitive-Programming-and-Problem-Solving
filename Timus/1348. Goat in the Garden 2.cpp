
#include <bits/stdc++.h>
using namespace std;

struct Point {
    long double x, y;
};

long double distance(const Point& p1, const Point& p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

long double getMinDistance(const Point& p1, const Point& p2, const Point& c) {
    Point left = p1;
    Point right = p2;
    long double minDistance = distance(c, p1);

    while(distance(right, left) > 1e-9) {
        Point mid1;
        mid1.x = (2 * left.x + right.x) / 3;
        mid1.y = (2 * left.y + right.y) / 3;

        Point mid2;
        mid2.x = (left.x + 2 * right.x) / 3;
        mid2.y = (left.y + 2 * right.y) / 3;

        long double d1 = distance(c, mid1);
        long double d2 = distance(c, mid2);

        minDistance = min({minDistance, d1, d2});

        (d1 < d2) ? right = mid2 : left = mid1;
    }

    return minDistance;
}

void solve() {

    Point a, b, c;
    long double l;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> l;

    long double maxDistance = max(distance(c, a), distance(c, b));
    long double minDistance = getMinDistance(a, b, c);

    cout << fixed << setprecision(2);
    cout << max((long double) 0, minDistance - l) << '\n';
    cout << max((long double) 0, maxDistance - l) << '\n';

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