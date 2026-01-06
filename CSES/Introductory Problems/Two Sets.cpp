#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    int n;
    cin >> n;
    long long sum = 1LL * n * (n + 1) / 2;
    if(sum & 1) {
        cout << "NO" << '\n';
        return;
    }
    vector<int> set1, set2;
    int curr = n;
    long long sum1 = 0, sum2 = 0;
    while(curr) {
        if(curr <= (sum / 2) - sum1) {
            sum1 += curr;
            set1.push_back(curr);
            curr--;
        } else {
            sum2 += curr;
            set2.push_back(curr);
            curr--;
        }
    }
    cout << "YES" << '\n';
    cout << set1.size() << '\n';
    for(auto it = set1.begin(); it != set1.end(); it++) {
        cout << *it << " \n"[next(it) == set1.end()];
    }
    cout << set2.size() << '\n';
    for(auto it = set2.begin(); it != set2.end(); it++) {
        cout << *it << " \n"[next(it) == set2.end()];
    }
 
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
