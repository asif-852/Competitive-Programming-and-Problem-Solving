
#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int k;
    cin >> k;
    multiset<int> s;
    for(int i = 0; i < k; i++) {
        s.insert(v[i]);
    }
    for(int i = k; i < n; i++) {
        cout << *s.rbegin() << " ";
        s.erase(s.find(v[i - k]));
        s.insert(v[i]);
    }
    cout << *s.rbegin() << '\n';
 
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