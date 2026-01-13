
#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    long long ans = 0, currsum = 0;
    map<long long, long long> seen;
    seen[0] = 1;
    for(auto u : v) {
        currsum += u;
        ans += seen[currsum - x];
        seen[currsum]++;
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
