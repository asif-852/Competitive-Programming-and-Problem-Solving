#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    long long ans = -1e18, curr = 0;
    for(auto u : v) {
        curr += u;
        ans = max(ans, curr);
        curr = max(curr, 0LL);
    }
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