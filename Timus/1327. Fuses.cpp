
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int l, r;
    cin >> l >> r;
    cout << (r+1)/2 - l/2 << '\n';
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