
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int x, y, a, b, c, d;
    cin >> x >> y >> a >> b >> c >> d;
    cout << d - y << " " << a - x << '\n';
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