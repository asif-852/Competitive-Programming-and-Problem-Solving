

#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[50][3];      // 0 -> W, 1 -> R, 2 -> B

long long f(int curridx, int lastcolor) {
    if(curridx == n) {
        return 1;
    }

    if(dp[curridx][lastcolor] != -1) {
        return dp[curridx][lastcolor];
    }

    int ret = 0;
    if(lastcolor == 0) {  // Last was W, Next must be R or BR
        ret += f(curridx + 1, 1);  // Place R
        if(curridx < n - 1) {
            ret += f(curridx + 2, 1);  // Place BR
        }
    }
    if(lastcolor == 1) {  // Last was R, Next must be W or BW
        ret += f(curridx + 1, 0);  // Place W
        if(curridx < n - 1) {
            ret += f(curridx + 2, 0);  // Place BW
        }
    }
    return dp[curridx][lastcolor] = ret;


}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(1, 0) + f(1, 1) << '\n';
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


// Alternative more generic solution
/*

#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[50][4][4];  // dp[index][last_color][before_last_color]
                         // 0 -> W, 1 -> B, 2 -> R, 3 -> None

long long f(int curridx, int last_color, int before_last_color) {
    if(curridx == n) {
        return (last_color == 0 || last_color == 2) ? 1 : 0;  // Only W or R are valid endings
    }

    if(dp[curridx][last_color][before_last_color] != -1) {
        return dp[curridx][last_color][before_last_color];
    }

    long long ret = 0;
    for(int color = 0; color < 3; color++) {  // 0: W, 1: B, 2: R
        // First stripe can't be blue
        if(curridx == 0 && color == 1) {
            continue;
        }
        // Same color as previous is not allowed
        if(last_color != 3 && color == last_color) {  // 3 represents "None"
            continue;
        }
        // If previous was B, next must be opposite of before_last
        if(last_color == 1) {
            int required = (before_last_color == 0) ? 2 : 0;
            if(color != required) {
                continue;
            }
        }
        ret += f(curridx + 1, color, last_color);
    }
    return dp[curridx][last_color][before_last_color] = ret;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(0, 3, 3) << '\n';  // Start with "None" state (3)
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

*/