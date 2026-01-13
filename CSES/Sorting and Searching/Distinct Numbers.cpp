
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    while(n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    cout << cnt.size() <<'\n';
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