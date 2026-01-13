// Approach 1: Greedy Algorithm

#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].second;
        cin >> v[i].first;
    }
    sort(v.begin(), v.end());
    int curr_max = v[0].first, ans = 1;
    for(int i = 1; i < n; i++) {
        if(v[i].second >= curr_max) {
            ans++;
            curr_max = v[i].first;
        }
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



// Approach 2: Dynamic Programming + Binary Search

/*

#include <bits/stdc++.h>
using namespace std;
 
int f(int idx, vector<pair<int, int>>& v, vector<int>& dp) {
    if(idx >= v.size()) return 0;
    if(dp[idx] != -1) return dp[idx];
 
    int way1 = f(idx + 1, v, dp);
    pair<int, int> temp = {v[idx].second, 0};
    int nextidx = lower_bound(v.begin(), v.end(), temp) - v.begin();
    int way2 = 1 + f(nextidx, v, dp);
 
    return dp[idx] = max(way1, way2);
}
 
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector<int> dp(n, -1);
    cout << f(0, v, dp) << '\n';
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



*/