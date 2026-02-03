
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    vector<int> nums;
    if(n <= 0) {
        for(int i = n; i <= 1; i++) {
            nums.push_back(i);
        }
    } else {
        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
    }

    cout << accumulate(nums.begin(), nums.end(), 0LL) << '\n';
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