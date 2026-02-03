
#include <bits/stdc++.h>
using namespace std;


void solve() {

    int n;
    cin >> n;
    double radius = -1e9;
    while(n--) {
        int x, y;
        cin >> x >> y;
        radius = max(radius, sqrt(x * x + y * y));
    }
    cout << fixed << setprecision(9) << "0 0 " << radius << '\n';

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