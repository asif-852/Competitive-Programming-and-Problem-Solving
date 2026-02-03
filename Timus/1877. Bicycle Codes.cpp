
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = stoi(s1);
    int n2 = stoi(s2);
    cout << ((n1 % 2 == 0 || n2 % 2 == 0) ? "yes" : "no") << '\n';
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