#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    
    long long n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0, j = n - 1; i < j;) {
        (v[i] + v[j] <= x) ? n--, i++, j-- : j--;
    }
    cout << n << '\n';
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