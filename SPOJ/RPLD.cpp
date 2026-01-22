
#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    map<pair<int, int>, int> cnt;
    int N, R;
    cin >> N >> R;
    for(int i = 0; i < R; i++) {
        int l, c;
        cin >> l >> c;
        cnt[{l, c}]++;
    }
    cout << (cnt.size() == R ? "possible" : "impossible") << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Scenario #" << i << ": ";
        solve();
    }
 
    return 0;
} 