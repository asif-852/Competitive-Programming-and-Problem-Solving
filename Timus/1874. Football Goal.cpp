
#include <bits/stdc++.h>
using namespace std;


long double calculate_area(long double a, long double b, long double c) {
    long double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c)) + (c * c) / 4;
}

void solve() {
    long double a, b;
    cin >> a >> b;

    long double l = 0, r = a + b, ans;
    while(r - l > 1e-9) {
        long double mid1 = (2 * l + r) / 3;
        long double mid2 = (l + 2 * r) / 3;
        long double area1 = calculate_area(a, b, mid1);
        long double area2 = calculate_area(a, b, mid2);
        (area1 > area2) ? r = mid2 : l = mid1;
        ans = area1;
    }
    cout << fixed << setprecision(9) << ans << '\n';

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