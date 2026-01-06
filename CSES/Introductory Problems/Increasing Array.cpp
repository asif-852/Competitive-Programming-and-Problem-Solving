#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    long long ans = 0;
    for(int i = 1; i < n; i++) {
        if(v[i] < v[i - 1]) {
            ans += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    cout << ans << '\n';
 
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
