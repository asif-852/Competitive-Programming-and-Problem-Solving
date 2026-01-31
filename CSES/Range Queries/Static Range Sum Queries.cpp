
#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    partial_sum(v.begin(), v.end(), v.begin());
 
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l - 1] << '\n';
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