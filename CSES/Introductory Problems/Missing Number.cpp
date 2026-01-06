#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    int n;
    cin >> n;
    vector<int> cnt(2e6);
    while(n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i = 1; i <= 200000; i++) {
        if(!cnt[i]) {
            cout << i << '\n';
            break;
        }
    }
 
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
