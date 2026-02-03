
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i = 1; i <= n; i++) {
        cout << fixed << setprecision(2) << (cnt[i] * 100.0) / m << "%" << '\n';
    }
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