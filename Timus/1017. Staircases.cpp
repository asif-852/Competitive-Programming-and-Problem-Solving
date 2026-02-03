
#include <bits/stdc++.h>
using namespace std;

const int N = 501;
long long dp[N][N];

long long f(int remaining, int min_step) {
    if(remaining == 0) {
        return 1;
    }
    if(dp[remaining][min_step] != -1) {
        return dp[remaining][min_step];
    }

    long long ans = 0;
    for(int steps = remaining; steps >= min_step; steps--) {
        ans += f(remaining - steps, steps + 1);
    }
    return dp[remaining][min_step] = ans;
}

void solve() {

    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(n, 1) - 1 << '\n';

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