
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    map<char, int> cost;
    int j = 0;
    for(char i = 'a'; i <= 'z'; i++, j++) {
        cost[i] = (j % 3) + 1;
    }
    cost[' '] = 1;
    cost['.'] = 1;
    cost[','] = 2;
    cost['!'] = 3;
    int ans = 0;
    string s;
    getline(cin, s);
    for(auto c : s) {
        ans += cost[c];
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