
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
 
    for(int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while(l < r) {
            int sum = v[l].first + v[r].first + v[i].first;
            if(sum == x) {
                cout << v[i].second << " " << v[l].second << " " << v[r].second << '\n';
                return;
            }
            (sum < x) ? l++ : r--;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
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


