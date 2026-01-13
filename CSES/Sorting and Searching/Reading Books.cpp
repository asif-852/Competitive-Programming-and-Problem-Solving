
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
 
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    sort(v.begin(), v.end());
    int biggest = v.back();
    long long rem = accumulate(v.begin(), v.end() - 1, 0LL);
    cout << (biggest > rem ? 2 * biggest : biggest + rem) << '\n';
 
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
