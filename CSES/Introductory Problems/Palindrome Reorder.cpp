#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    string s;
    cin >> s;
    map<char, int> cnt;
    for(auto u : s) cnt[u]++;
    int oddcnt = 0;
    char oddchar = '!';
    for(auto u : cnt) {
        if(u.second & 1) {
            oddchar = u.first;
            oddcnt++;
        }
    }
    if(oddcnt > 1) {
        cout << "NO SOLUTION" << '\n';
        return;
    }
    string half;
    for(auto u : cnt) {
        if(u.first != oddchar) {
            half += string(u.second / 2, u.first);
        }
    }
    string ans = half;
    if(oddchar != '!') ans += string(cnt[oddchar], oddchar);
    reverse(half.begin(), half.end());
    ans += half;
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
