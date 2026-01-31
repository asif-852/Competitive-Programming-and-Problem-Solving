
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
 
void solve() {
    ordered_set<pair<int, int>> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert({i, x});
    }
 
    for(int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        auto toRemove = s.find_by_order(pos - 1);
        auto [_, val] = *toRemove;
        cout << val << " \n"[i == n - 1];
        s.erase(toRemove);
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
