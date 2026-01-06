#include <bits/stdc++.h>
using namespace std;
 
int fact(int n) {
    return n ? n * fact(n - 1) : 1;
}
 
void solve() {
 
    vector<string> v;
    string s;
    cin >> s;
    map<char, int> cnt;
    for(auto c : s) cnt[c]++;
    int permutation = fact((int) s.size());
    for(auto u : cnt) {
        permutation /= fact(u.second);
    }
    cout << permutation << '\n';
    while(permutation--) {
        next_permutation(s.begin(), s.end());
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for(auto u : v) cout << u << '\n';
 
}
 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}