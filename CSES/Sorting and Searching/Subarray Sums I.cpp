
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    partial_sum(a.begin(), a.end(), a.begin());
    long long ans = 0;
    for(int j = 0, i = 1; i <= n;) {
        if(a[i] - a[j] == k) {
            ans++, i++;
        }
        else {
            (a[i] - a[j] < k) ? i++ : j++;
        }
    }
    cout << ans << '\n';

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