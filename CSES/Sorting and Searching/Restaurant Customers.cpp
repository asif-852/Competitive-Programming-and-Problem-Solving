#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    map<int, int> cnt;
    int n;
    cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;
        cnt[x]++;
        cnt[y]--;
    }
    //debug(cnt);
    long long sum = 0, ans = 0;
    for(auto u : cnt) {
        sum += u.second;
        ans = max(ans, sum);
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