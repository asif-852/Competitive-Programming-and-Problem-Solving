
// Approach 1: Recursive DP with Memoization


#include <bits/stdc++.h>
using namespace std;


string s1, s2, s3;
int len1, len2, len3;
int dp[50][50][50];

int rec(int i, int j, int k) {
    if(i == len1 || j == len2 || k == len3) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];

    if(s1[i] == s2[j] && s1[i] == s3[k]) {
        return dp[i][j][k] = 1 + rec(i + 1, j + 1, k + 1);
    }
    return dp[i][j][k] = max({rec(i + 1, j, k), rec(i, j + 1, k), rec(i, j, k + 1)});
}

void solve() {
    cin >> s1 >> s2 >> s3;
    len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << '\n';
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


















// Approach 2: Iterative DP

/*
#include <bits/stdc++.h>
using namespace std;


void solve() {

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
    s1.insert(s1.begin(), '!');
    s2.insert(s2.begin(), '!');
    s3.insert(s3.begin(), '!');
    vector<vector<vector<int>>> dp(len1 + 1, vector<vector<int>>(len2 + 1, vector<int>(len3 + 1)));
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            for(int k = 1; k <= len3; k++) {
                if(s1[i] == s2[j] && s1[i] == s3[k]) {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                }
                else {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }
    cout << dp[len1][len2][len3] << '\n';

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

*/