
#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    long long N, SUM;
    cin >> N >> SUM;
    int n1 = (N + 1) / 2, n2 = N - n1;
    vector<int> v(N);
    for(auto& x : v) cin >> x;
 
    vector<long long> l, r;
    for(int i = 0; i < N; i++) {
        long long val = v[i];
        (i < n1) ? l.push_back(val) : r.push_back(val);
    }
 
    vector<long long> left, right;
    for(int mask = 0; mask < (1 << n1); mask++) {
        long long sum = 0;
        for(int i = 0; i < n1; i++) {
            if(mask & (1 << i)) {
                sum += l[i];
            }
        }
        left.push_back(sum);
    }
    for(int mask = 0; mask < (1 << n2); mask++) {
        long long sum = 0;
        for(int i = 0; i < n2; i++) {
            if(mask & (1 << i)) {
                sum += r[i];
            }
        }
        right.push_back(sum);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
 
    long long ans = 0;
    for(auto u : left) {
        int low = lower_bound(right.begin(), right.end(), SUM - u) - right.begin();
        int high = upper_bound(right.begin(), right.end(), SUM - u) - right.begin();
        ans += high - low;
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
 
