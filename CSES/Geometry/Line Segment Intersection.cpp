
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
 
bool onSegment(const Point p, const Point a, const Point b) {
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}
 
bool intersects(const Point a, const Point b, const Point c, const Point d) {
    int d1 = orientation(c, a, b);
    int d2 = orientation(d, a, b);
    int d3 = orientation(a, c, d);
    int d4 = orientation(b, c, d);
 
    if(d1 != d2 && d3 != d4) return true;
 
    if(d1 == 0 && onSegment(c, a, b)) return true;
    if(d2 == 0 && onSegment(d, a, b)) return true;
    if(d3 == 0 && onSegment(a, c, d)) return true;
    if(d4 == 0 && onSegment(b, c, d)) return true;
 
    return false;
}
 
void solve() {
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    cout << (intersects(p1, p2, p3, p4) ? "YES" : "NO") << '\n';
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
