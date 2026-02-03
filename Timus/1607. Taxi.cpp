
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    long long petr, i1, taxi, d1;
    cin >> petr >> i1 >> taxi >> d1;
    if(petr > taxi) {
        cout << petr << '\n';
        return;
    }
    while(1) {
        // debug(petr,taxi);
        if(petr + i1 <= taxi) {
            petr += i1;
        } else {
            cout << taxi << '\n';
            return;
        }
        
        if(taxi - d1 >= petr) {
            taxi -= d1;
        } else {
            cout << petr << '\n';
            return;
        }
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