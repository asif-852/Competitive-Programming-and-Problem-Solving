#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n, k;
    cin >> n >> k;
    multiset<int> s = {-1};
    while(n--) {
        int x;
        cin >> x;
        s.insert(x);
    }
 
    while(k--) {
        int x;
        cin >> x;
        auto it = s.upper_bound(x);
        cout << *--it << '\n';
        if(*it != -1) {
            s.erase(it);
        }
    }

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