
#include <bits/stdc++.h>
using namespace std;

long long bin_to_dec(string s) {
    long long n = 0;
    for(int i = 0; i < 32; i++) {
        n = (2 * n) + s[i] - '0';
    }
    return n;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    int a = 32 - k;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string temp = string(a, '0') + s;
        v[i] = bin_to_dec(temp);
    }
 
    int ans = 1e9;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ans = min(ans, __builtin_popcount(v[i] ^ v[j]));
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