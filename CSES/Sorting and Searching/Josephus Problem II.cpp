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

    int n, k;
    cin >> n >> k;
    ordered_set<int> st;
    for(int i = 1; i <= n; i++) {
        st.insert(i);
    }
    int curridx = 0;
    while(!st.empty()) {
        curridx = ((curridx + k - 1)) % st.size();
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

// Approach 2: Binary Indexed Tree (Fenwick Tree)

/*

#include <bits/stdc++.h>
using namespace std;


struct BIT {
    vector<long long> M, A;
    BIT(int n) {
        init(n);
    }
    void init(int n) {
        M.assign(n + 1, 0);
        A.assign(n + 1, 0);
    }
    void update(int i, long long mul, long long add) {
        while (i < (int)M.size()) {
            M[i] += mul;
            A[i] += add;
            i |= (i + 1);
        }
    }
    void rangeUpdate(int l, int r, long long x) {
        update(l, x, -x * (l - 1));
        update(r, -x, x * r);
    }
    long long query(int i) {
        long long mul = 0, add = 0;
        int st = i;
        while (i >= 0) {
            mul += M[i];
            add += A[i];
            i = (i & (i + 1)) - 1;
        }
        return (mul * st + add);
    }
    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }

    // Smallest index idx such that prefixSum(idx) >= k (k is 1-indexed)
    // This uses the internal Fenwick tree values in A[] (works when using update(i, 0, delta)).
    int kth(long long k) {
        int idx = -1;
        long long cur = 0;

        int bitMask = 1;
        while(bitMask < (int)A.size()) {
            bitMask <<= 1;
        }
        bitMask >>= 1;

        for(int step = bitMask; step > 0; step >>= 1) {
            int nxt = idx + step;
            if(nxt < (int)A.size() && cur + A[nxt] < k) {
                cur += A[nxt];
                idx = nxt;
            }
        }
        return idx + 1;
    }
};


void solve() {

    int n;
    long long k;
    cin >> n >> k;

    // We keep index 0 unused, and store alive counts at indices [1..n].
    BIT bit(n);
    for(int i = 1; i <= n; i++) {
        bit.update(i, 0, 1);
    }

    long long curridx = 0;
    for(int i = n; i >= 1; i--) {
        curridx = (curridx + k) % i;
        int pos = bit.kth(curridx + 1);
        cout << pos << " \n"[i == 1];
        bit.update(pos, 0, -1);
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
