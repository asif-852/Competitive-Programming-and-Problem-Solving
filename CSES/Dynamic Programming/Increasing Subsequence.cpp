
#include <bits/stdc++.h>
using namespace std;
 
 
vector<int> getLIS(vector<int>& v) {
    int n = v.size();
    vector<int> dp(n, 1);
    vector<int> lis = {v[0]};
    for (int i = 1; i < v.size(); i++) {
        int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        if (index == lis.size()) {
            lis.push_back(v[i]);
        } else {
            lis[index] = v[i];
        }
        dp[i] = lis.size();
    }
    return dp;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    cout << getLIS(v)[n - 1] << '\n';
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
 
