
#include <bits/stdc++.h>
using namespace std;

void solve() {
    double AB, AC, BC, r;
    cin >> AB >> AC >> BC >> r;
    cout << fixed << setprecision(6) << AB * sqrt(r / (r + 1)) << '\n';
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