
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int f;
    cin >> f;
    cout << ((12 - f) * 45 <= 240 ? "YES" : "NO") << '\n';
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