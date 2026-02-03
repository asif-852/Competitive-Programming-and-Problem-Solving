
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    map<string, bool> vis;
    while(n--) {
        char c;
        cin >> c;
        string s;
        getline(cin, s);
        s = c + s;
        if(vis[s]) cnt++;
        vis[s] = 1;
    }
    cout << cnt << '\n';
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