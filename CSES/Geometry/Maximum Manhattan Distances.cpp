
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    multiset<long long> s1, s2;
    for(int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        s1.insert(x + y);
        s2.insert(x - y);
        long long ans = max(*s1.rbegin() - *s1.begin(), *s2.rbegin() - *s2.begin());
        cout << ans << '\n';
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