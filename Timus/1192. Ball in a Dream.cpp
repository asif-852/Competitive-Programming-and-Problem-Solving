
#include <bits/stdc++.h>
using namespace std;

long double distance(long double v, long double a) {
    return v * v * sin((2 * a * 3.1415926535) / 180.0) * 0.1;
}

void solve() {

    long double v, a, k;
    cin >> v >> a >> k;
    long double ans = distance(v, a);
    ans *= k;
    ans /= (k - 1);
    cout << fixed << setprecision(2) << ans << '\n';

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