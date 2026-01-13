
#include <bits/stdc++.h>
using namespace std;

string word1, word2;
int dp[5001][5001];

int f(int idx1, int idx2) {
    if(idx1 == word1.size()) {
        return word2.size() - idx2;
    }
    if(idx2 == word2.size()) {
        return word1.size() - idx1;
    }
    if(dp[idx1][idx2] != -1) {
        return dp[idx1][idx2];
    }

    int ans = 2e9;
    if(word1[idx1] == word2[idx2]) {
        ans = f(idx1 + 1, idx2 + 1);
    } else {
        ans = min({ans, 1 + f(idx1 + 1, idx2), 1 + f(idx1, idx2 + 1), 1 + f(idx1 + 1, idx2 + 1)});
    }
    return dp[idx1][idx2] = ans;
}
 
void solve() {
    cin >> word1 >> word2;
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0) << '\n';
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
