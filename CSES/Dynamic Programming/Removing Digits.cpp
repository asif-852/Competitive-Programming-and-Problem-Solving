
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    int steps = 0;
    while(n) {
        string s = to_string(n);
        char c = *max_element(s.begin(), s.end());
        n -= (c - '0');
        steps++;
    }
    cout << steps << '\n';
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