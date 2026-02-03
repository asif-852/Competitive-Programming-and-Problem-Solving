
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int t1, t2;
    cin >> t1 >> t2;
    int penalty = 0;
    for(int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        penalty += x * 20;
    }
    cout << ((t1 + penalty <= t2) ? "No chance." : "Dirty debug :(") << '\n';
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