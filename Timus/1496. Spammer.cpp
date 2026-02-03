
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    map<string, int> cnt;
    while(n--) {
        string s;
        cin >> s;
        cnt[s]++;
    }
    for(auto [str, count] : cnt) {
        if(count >= 2) cout << str << '\n';
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