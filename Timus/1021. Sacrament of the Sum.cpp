
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n1;
    cin >> n1;
    vector<int> v1(n1);
    for(auto &x : v1) cin >> x;

    int n2;
    cin >> n2;
    vector<int> v2(n2);
    for(auto &x : v2) cin >> x;

    for(int u : v2) {
        if(binary_search(v1.begin(), v1.end(), 10000 - u)) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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