#include <bits/stdc++.h>
using namespace std;
 

void solve() {

    int n;
    cin >> n;
    vector<int> v;
    while(n--) {
        int x;
        cin >> x;
        auto it = upper_bound(v.begin(), v.end(), x);
        if(it == v.end()) {
            v.push_back(x);
        }
        else {
            *it = x;
        }
    }
    cout << v.size() << '\n';
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