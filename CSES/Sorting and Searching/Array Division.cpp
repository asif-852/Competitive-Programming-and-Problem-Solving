
#include <bits/stdc++.h>
using namespace std;
 
bool high_enough(long long mid, vector<int> &v, int k) {
    int cnt = 1;
    long long sum = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > mid) return false;
 
        sum += v[i];
        if(sum > mid) {
            cnt++;
            sum = v[i];
        }
    }
    return cnt <= k;
}
 
void solve() {
 
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
 
    long long low = 0;
    long long high = accumulate(v.begin(), v.end(), 0LL);
    long long ans = -1;
    while(low <= high) {
        long long mid = (low + high) / 2;
        (high_enough(mid, v, k)) ? high = mid - 1, ans = mid : low = mid + 1;
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
