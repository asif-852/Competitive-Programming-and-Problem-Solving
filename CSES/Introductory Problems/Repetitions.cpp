#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    string s;
    cin >> s;
    int ans = 1, cnt = 1;
    for(int i = 1; i < s.size(); i++) {
        char c = s[i];
        if(c == s[i - 1]) {
            cnt++;
            ans = max(ans, cnt);
        }
        else cnt = 1;
    }
    cout << ans << '\n';
 
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
