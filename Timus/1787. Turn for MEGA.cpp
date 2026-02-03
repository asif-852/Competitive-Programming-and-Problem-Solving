
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int k, n;
    cin >> k >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    for(int i = 0; i < n - 1; i++) {
        v[i] = max(0, v[i] - k);
        v[i + 1] += v[i];
    }
    cout << max(0, v.back() - k) << '\n';
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