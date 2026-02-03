
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    while(n--) {
        string s;
        cin >> s;
        (s.find("+") != string::npos) ? cnt += 2 : cnt += 1;
    }
    cnt += 2;

    cout << ((cnt == 13) ? 1400 : cnt * 100) << '\n';
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