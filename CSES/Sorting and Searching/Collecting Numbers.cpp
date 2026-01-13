#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    map<int, int> pos;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    int ans = 1;
    for(int i = 2; i <= n; i++) {
        if(pos[i - 1] > pos[i]) ans++;
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