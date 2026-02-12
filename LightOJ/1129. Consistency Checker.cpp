
#include <bits/stdc++.h>
using namespace std;

bool prefix_match(string small, string big) {
    int len = small.size();
    if(big.size() <= len) return false;
    return big.substr(0, len) == small;
}

void solve() {

    int n;
    cin >> n;
    vector<string> v(n);
    for(auto& x : v) cin >> x;
    sort(v.begin(), v.end());
    bool bad = 0;
    for(int i = 0; i < n - 1; i++) {
        bad |= prefix_match(v[i], v[i + 1]);
    }
    cout << (bad ? "NO" : "YES") << '\n';

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}