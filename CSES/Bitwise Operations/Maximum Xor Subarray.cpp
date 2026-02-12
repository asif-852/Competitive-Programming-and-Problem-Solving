
#include <bits/stdc++.h>
using namespace std;
 
const int N = 8e6 + 1;
int nxt[N][2];
int total = 1;
 
void add_string(string s) {
    int curr = 1;
    for(int i = 0; i < s.size(); i++) {
        int ch = s[i] - '0';
        if(!nxt[curr][ch]) {
            nxt[curr][ch] = ++total;
        }
        curr = nxt[curr][ch];
    }
}
 
int query(string t) {
    int n = t.size();
    int ans = 0;
    int curr = 1;
    for(int i = 0; i < n; i++) {
        int ch = 1 - (t[i] - '0');
        if(nxt[curr][ch]) {
            ans += (1 << (n - i - 1));
        } else {
            ch ^= 1;
        }
        curr = nxt[curr][ch];
    }
    return ans;
}
 
void solve() {
 
    int n;
    cin >> n;
    n++;
    vector<int> v(n);
    for(int i = 1; i < n; i++) {
        cin >> v[i];
    }
    partial_sum(v.begin(), v.end(), v.begin(), [](int a, int b) {
        return a ^ b;
    });
    for(int i = 0; i < n; i++) {
        add_string(bitset<32>(v[i]).to_string());
    }
    int ans = 0;
    for(auto u : v) {
        int mx = query(bitset<32>(u).to_string());
        ans = max(ans, mx);
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
