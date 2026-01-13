// Approach 1: Ordered Set (Policy Based Data Structure)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

void solve() {

    int n;
    cin >> n;
    ordered_set<int> st;
    for(int i = 1; i <= n; i++) {
        st.insert(i);
    }
    int curridx = 0;
    while(!st.empty()) {
        curridx = ((curridx + 1)) % st.size();
        auto it = st.find_by_order(curridx);
        cout << *it << " \n"[st.size() == 1];
        st.erase(it);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}

// Approach 2: Simulation with Queue

/*

#include <bits/stdc++.h>
using namespace std;


void solve() {

    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    while(!q.empty()) {
        q.push(q.front());
        q.pop();
        cout << q.front() << " \n"[q.size() == 1];
        q.pop();
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

*/