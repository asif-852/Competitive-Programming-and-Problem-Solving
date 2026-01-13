
#include <bits/stdc++.h>
using namespace std;
 
long long countMax(int idx, vector<tuple<int, int, int>>& v, vector<long long>& dp) {
    if(idx >= v.size()) return 0;
    if(dp[idx] != -1) return dp[idx];
 
    long long way1 = countMax(idx + 1, v, dp);
 
    auto [start, end, profit] = v[idx];
    tuple<int, int, int> temp = {end + 1, -1, -1};
    int nextidx = lower_bound(v.begin(), v.end(), temp) - v.begin();
    long long way2 = profit + countMax(nextidx, v, dp);
 
    return dp[idx] = max(way1, way2);
}
 
 
void solve() {
 
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v;
    for(int i = 0; i < n; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        v.push_back({a, b, p});
    }
    sort(v.begin(), v.end());
    vector<long long> dp(n, -1);
    cout << countMax(0, v, dp) << '\n';
 
 
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
