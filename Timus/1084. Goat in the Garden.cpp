
#include <bits/stdc++.h>
using namespace std;

const double pi = 3.1415926;

void solve() {
    cout << fixed << setprecision(3);
    
    double a, r;
    cin >> a >> r;
    if(r >= a / sqrt(2)) {
        cout << a * a << '\n';
        return;
    }
    if(r <= a / 2) {
        cout << pi * r * r << '\n';
        return;
    }
    double ans = pi * r * r;
    double theta = acos((0.5 * a) / r);
    double reduce = (0.5 * r * r * theta) - (0.5 * r * (a / 2) * sin(theta));
    ans -= 8 * reduce;
    cout << ans << '\n';

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