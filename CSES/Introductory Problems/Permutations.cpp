#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    int n;
    cin >> n;
    if(n == 2 || n == 3) {
        cout << "NO SOLUTION" << '\n';
        return;
    }
    cout << n / 2 + 1 << " ";
    for(int i = 1, j = n; i <= (n - 1) / 2; i++, j--) {
        cout << i << " " << j << " ";
    }
    if(n % 2 == 0) {
        cout << n / 2 << '\n';
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