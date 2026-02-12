
#include <bits/stdc++.h>
using namespace std;

vector<int> digits;
int l, r, k, n;
int dp[10][90][90][2];

int f(int idx, int rem1, int rem2, int tight) {
    if(idx == n) {
        return (rem1 == 0 && rem2 == 0);
    }
    if(dp[idx][rem1][rem2][tight] != -1) {
        return dp[idx][rem1][rem2][tight];
    }

    int limit = tight ? (digits[idx]) : 9;
    long long ret = 0;
    for(int i = 0; i <= limit; i++) {
        ret += f(idx + 1, (rem1 + i) % k, ((rem2 * 10) + i) % k, (tight && i == limit));
    }
    return dp[idx][rem1][rem2][tight] = ret;
}

int calc(int val) {
    digits.clear();
    string s = to_string(val);
    for(int i = 0; i < s.size(); i++) {
        digits.push_back(s[i] - '0');
    }
    n = digits.size();
    memset(dp, -1, sizeof(dp));
    return f(0, 0, 0, 1);
}

void solve() {
    cin >> l >> r >> k;
    cout << (k > 90 ? 0 : calc(r) - calc(l - 1)) << '\n';
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