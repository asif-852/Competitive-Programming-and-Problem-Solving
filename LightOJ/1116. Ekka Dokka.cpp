
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    long long w;
    cin >> w;
    if(w % 2) {
        cout << "Impossible" << '\n';
        return;
    }

    long long temp = w;
    while(temp > 1) {
        if(temp % 2) {
            cout << temp << " " << w / temp << '\n';
            break;
        }
        temp /= 2;
    }

    if(temp == 1) {
        cout << "Impossible" << '\n';
    }


}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}