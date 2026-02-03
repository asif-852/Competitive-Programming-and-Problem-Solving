
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int k = 3;
    map<int, int> cnt;
    while(k--) {
        int n;
        cin >> n;
        while(n--) {
            int x;
            cin >> x;
            cnt[x]++;
        }
    }
    int ans = 0;
    for(auto u : cnt) {
        ans += (u.second == 3);
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