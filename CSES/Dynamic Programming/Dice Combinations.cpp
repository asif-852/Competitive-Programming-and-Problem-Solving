// Approach 1: Iterative DP

#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
        for(int j = 1; j <= min(i, 6); j++) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    cout<< dp[n] <<'\n';

    // Generalized approach
    /*
    int n;
    cin >> n;
    vector<int> dice = {1, 2, 3, 4, 5, 6};
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        //debug(i);
        for(auto k : dice) {
            if(i - k >= 0) {
                dp[i] += dp[i - k];
                dp[i] %= MOD;
            }
            //debug(k, dp);
            cout<<'\n';
        }
    }
 
    cout << dp[n] << '\n';
    */
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




// Approach 2: Recursive DP with Memoization

/*

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
 
vector<long long> dp(1e6 + 1);
long long number_of_ways(long long n) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n]) return dp[n];
 
    for(int i = 1; i <= 6; i++) {
        dp[n] += number_of_ways(n - i) % MOD;
    }
    return dp[n] % MOD;
}


void solve() {
    long long n;
    cin >> n;
    cout << number_of_ways(n) << '\n';
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

*/



