
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    long long area = 0;
    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += x[i] * y[j] - x[j] * y[i];
    }
    cout << abs(area) << '\n';
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