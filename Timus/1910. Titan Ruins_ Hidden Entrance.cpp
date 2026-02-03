
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    int mx = 0, mid;
    for(int i = 1; i < n - 1; i++) {
        if(a[i - 1] + a[i] + a[i + 1] > mx) {
            mx = a[i - 1] + a[i] + a[i + 1];
            mid = i + 1;
        }
    }
    cout << mx << " " << mid << '\n';
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