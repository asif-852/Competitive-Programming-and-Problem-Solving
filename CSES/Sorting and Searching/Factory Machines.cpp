
#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for(auto &x : v) cin >> x;
    long long l = 0, r = 1e18;
 
    while(l + 1 < r) {
        long long mid = (l + r) >> 1;
        long double cnt = 0;
        for(auto u : v) {
            cnt += mid / u;
        }
        (cnt >= k) ? r = mid : l = mid;
    }
    cout << r << '\n';
 
 
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

