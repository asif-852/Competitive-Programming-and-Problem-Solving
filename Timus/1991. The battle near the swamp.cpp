
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int unused = 0, survived = 0;
    for(auto u : v) {
        if(u < k) survived += k - u;
        else if(u > k) unused += u - k;
    }
    cout << unused << " " << survived << '\n';
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