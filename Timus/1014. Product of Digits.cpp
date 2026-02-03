
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    if(n == 0) {
        cout << 10 << '\n';
        return;
    }
    if(n >= 1 && n <= 9) {
        cout << n << '\n';
        return;
    }

    string s = "";
    for(int i = 9; i >= 2; i--) {
        while(n % i == 0) {
            n /= i;
            s += (char) (i + '0');
        }
    }
    reverse(s.begin(), s.end());
    cout << (s.size() && n == 1 ? s : "-1") << '\n';
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