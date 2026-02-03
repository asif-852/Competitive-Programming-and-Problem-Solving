
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    
    int cnt = 1, last = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] != last) {
            cout << cnt << " " << last << " ";
            cnt = 1;
        } else {
            cnt++;
        }
        last = a[i];
    }
    cout << cnt << " " << last << '\n';
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