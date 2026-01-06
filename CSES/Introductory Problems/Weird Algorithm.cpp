#include <bits/stdc++.h>
using namespace std;


void solve() {

    long long n;
    cin >> n;
    while(n != 1) {
        cout << n << " ";
        (n & 1) ? n = 3 * n + 1 : n = n / 2;
    }
    cout << n << '\n';

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





















