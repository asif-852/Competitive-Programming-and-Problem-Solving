
#include <bits/stdc++.h>
using namespace std;
 
double x, y, c;

double obtained_height(double mid) {
    double a = sqrt((x * x) - (mid * mid));
    double b = sqrt((y * y) - (mid * mid));
    return ((a * b) / (a + b));
}


void solve() {
    cin >> x >> y >> c;
    double l = 0, r = min(x, y);
    while(l + 1e-7 < r) {
        double mid = (l + r) / 2;
        obtained_height(mid) <= c ? r = mid : l = mid;
    }
    cout << fixed << setprecision(12) << l << '\n';
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}