
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    map<int, bool> cnt;
    while(n--) {
        int x;
        cin >> x;
        cnt[x] = true;
    }

    int count = 0;
    int m;
    cin >> m;
    while(m--) {
        int y;
        cin >> y;
        count += cnt[y];
    }
    cout << count << '\n';
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