#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 5; i <= n; i *= 5) {
        cnt += (n / i);
    }
    cout << cnt << '\n';
 
}
 
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
