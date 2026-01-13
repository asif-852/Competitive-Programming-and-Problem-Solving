
#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    long long ans = 0;
    map<long long, long long> cnt;
    for(int l = 0, r = 0; r < n; r++) {
        cnt[v[r]]++;
        while(cnt.size() > k) {
            cnt[v[l]]--;
            if(cnt[v[l]] == 0) {
                cnt.erase(cnt.find(v[l]));
            }
            l++;
        }
        ans += (r - l + 1);
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
