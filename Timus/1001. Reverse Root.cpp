
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    long long x;
    vector<double> v;
    while(cin >> x) {
        v.push_back(sqrt(x));
    }
    for(int i = (int)v.size() - 1; i >= 0; i--) {
        cout << fixed << setprecision(4) << v[i] << '\n';
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