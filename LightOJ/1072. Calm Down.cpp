
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    double pi = acos(-1);
    double R, N;
    cin >> R >> N;
    double ans = (R * sin(pi / N)) / (1 + sin(pi / N));
    cout << fixed << setprecision(10) << ans << '\n';
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