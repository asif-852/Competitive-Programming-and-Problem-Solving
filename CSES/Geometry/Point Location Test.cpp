
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
 
void solve() {
    Point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    int val = orientation(p3, p1, p2);
    if(val == 0) {
        cout << "TOUCH" << '\n';
    } else {
        cout << (val == 1 ? "RIGHT" : "LEFT") << '\n';
    }
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
