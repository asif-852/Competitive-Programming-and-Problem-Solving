#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long m = v[n / 2], ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(v[i] - m);
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