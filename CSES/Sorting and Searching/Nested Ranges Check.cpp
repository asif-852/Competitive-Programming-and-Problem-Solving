
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 
template<typename T>
using ordered_multiset1 = tree<
    T,
    null_type,
    less_equal<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
 
template<typename T>
using ordered_multiset2 = tree<
    T,
    null_type,
    greater_equal<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
 
void solve() {
 
    int n;
    cin >> n;
    vector<tuple<int, int, int>> ranges;
    for(int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        ranges.push_back({start, end, i});
    }
    sort(ranges.begin(), ranges.end(), [&](const auto& l, const auto& r) {
        auto [start1, end1, _1] = l;
        auto [start2, end2, _2] = r;
        return start1 == start2 ? end1 > end2 : start1 < start2;
    });
 
 
    ordered_multiset1<int> os1;
    vector<bool> contains(n);
    for(int i = n - 1; i >= 0; i--) {
        auto [start, end, idx] = ranges[i];
        contains[idx] = os1.order_of_key(end + 1);
        os1.insert(end);
    }
 
 
    ordered_multiset2<int> os2;
    vector<bool> contained_by(n);
    for(auto [start, end, idx] : ranges) {
        contained_by[idx] = os2.order_of_key(end - 1);
        os2.insert(end);
    }
 
    for(int i = 0; i < n; i++) {
        cout << contains[i] << " \n"[i == n - 1];
    }
    for(int i = 0; i < n; i++) {
        cout << contained_by[i] << " \n"[i == n - 1];
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
