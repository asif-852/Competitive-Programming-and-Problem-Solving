
#include <bits/stdc++.h>
using namespace std;
 
long long lagging_zeros(long long n) {
    long long cnt = 0;
    for(long long i = 5; i <= n; i *= 5) {
        cnt += (n / i);
    }

    return cnt;
}


void solve() {
    int k;
    cin >> k;
    long long l = 1, r = 1e18, ans = -1;
    while(l <= r) {
        long long mid = (l + r) / 2;
        long long val = lagging_zeros(mid);
        (val < k) ? l = mid + 1 : (val > k) ? r = mid - 1 : ans = mid, r = mid - 1;
    }

    cout << (ans == -1 ? "impossible" : to_string(ans)) << '\n';
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}