
#include <bits/stdc++.h>
using namespace std;


void solve() {
    int type;
    double len1;
    cin >> type >> len1;
    if(type == 1) len1 *= 2;
    else if(type == 2) len1 *= sqrt(2);

    int n;
    cin >> n;
    int ans = 0;
    while(n--) {
        int type;
        double len2;
        cin >> type >> len2;
        if(type == 1) len2 *= 2;
        else if(type == 3) len2 *= sqrt(3) / 2;
        ans += (len2 <= len1);
    }
    cout << ans << '\n';
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