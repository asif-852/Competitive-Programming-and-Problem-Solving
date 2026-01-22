
#include <bits/stdc++.h>
using namespace std;
 
vector<int> digits;
long long l, r, n;
long long dp[16][145][2];
 
long long f(int idx, long long sum, int tight) {
    if(idx == n) return sum;
    if(dp[idx][sum][tight] != -1) return dp[idx][sum][tight];
 
    int limit = tight ? (digits[idx]) : 9;
    long long ret = 0;
    for(int i = 0; i <= limit; i++) {
        ret += f(idx + 1, sum + i, (tight && i == limit));
    }
    return dp[idx][sum][tight] = ret;
}
 
long long calc(long long val) {
    digits.clear();
    string s = to_string(val);
    for(int i = 0; i < s.size(); i++) {
        digits.push_back(s[i] - '0');
    }
    n = digits.size();
    memset(dp, -1, sizeof(dp));
    return f(0, 0, 1);
}
 
void solve() {
 
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
 
    return 0;
} 