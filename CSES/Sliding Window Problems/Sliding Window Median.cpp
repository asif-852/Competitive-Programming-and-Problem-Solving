
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 
template<typename T>
using ordered_multiset = tree<
    T,
    null_type,
    less_equal<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

ordered_multiset<int> s;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    for(int i = 0; i < n; i++) {
        s.insert(v[i]);
        int len = s.size(), ans;
        if(len > k) {
            s.erase(s.find_by_order(s.order_of_key(v[i - k])));
            len--;
        }
        if(len >= k) {
            if(len & 1) {
                ans = *(s.find_by_order(len / 2));
            } else {
                ans = *(s.find_by_order(len / 2 - 1));
            }
            cout << ans << " \n"[i == n - 1];
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