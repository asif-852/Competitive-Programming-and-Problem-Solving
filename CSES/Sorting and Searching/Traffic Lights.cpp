#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int len, n;
    cin >> len >> n;
    multiset<int, greater<int>> distance;
    set<int> curr;
    distance.insert(len);
    curr.insert(0);
    curr.insert(len);
    // debug(curr);
    while(n--) {
        int x;
        cin >> x;
        curr.insert(x);
        int l = *prev(curr.find(x));
        int r = *next(curr.find(x));
        // debug(l,r);
        auto it = distance.find(r - l);
        distance.erase(it);
        distance.insert(x - l);
        distance.insert(r - x);
        // debug(distance);
        cout << *distance.begin() << '\n';
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