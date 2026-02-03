
#include <bits/stdc++.h>
using namespace std;

long double distance(pair<long double, long double>& a, pair<long double, long double>& b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void solve() {

    int n;
    long double r;
    cin >> n >> r;
    vector<pair<long double, long double>> v(n + 1);
    for(int i = 0; i < n; i++) {
        long double x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    v[n] = v[0];

    long double ans = 0;
    for(int i = 0; i < n; i++) {
        ans += distance(v[i], v[i + 1]);
    }
    ans += 2 * 3.1415926 * r;
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