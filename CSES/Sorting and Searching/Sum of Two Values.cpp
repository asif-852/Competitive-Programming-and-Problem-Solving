#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    long long n, x;
    cin >> n >> x;
    vector<pair<long long, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
 
    for(int i = 0, j = n - 1; i < j;) {
        if(v[i].first + v[j].first == x) {
            cout << v[i].second + 1 << " " << v[j].second + 1 << '\n';
            return;
        }
        (v[i].first + v[j].first < x) ? i++ : j--;
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