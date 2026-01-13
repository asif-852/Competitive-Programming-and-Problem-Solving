#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long sum = 1;
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    for(auto u : v) {
        if(u <= sum) sum += u;
        else break;
    }
    cout << sum << '\n';
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