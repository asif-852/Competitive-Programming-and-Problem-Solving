
#include <bits/stdc++.h>
using namespace std;

template <typename T_Node, typename T_Lazy>
class SegmentTree {
   public:
    using Merger = function<T_Node(const T_Node&, const T_Node&)>;
    using Applier = function<void(T_Node&, const T_Lazy&, int, int)>;
    using Combiner = function<T_Lazy(const T_Lazy&, const T_Lazy&)>;
    using Builder = function<T_Node(int)>;

   private:
    int N;
    vector<T_Node> tree;
    vector<T_Lazy> lazy;
    T_Lazy no_lazy_val;
    T_Node identity_node_val;

    Merger merge_op;
    Applier apply_op;
    Combiner combine_op;
    Builder build_op;

    void push(int node, int L, int R) {
        if (lazy[node] != no_lazy_val && L != R) {
            int mid = L + (R - L) / 2;
            int left_child = 2 * node;
            int right_child = 2 * node + 1;

            T_Lazy parent_lazy_value_to_push = lazy[node];

            lazy[left_child] = combine_op(lazy[left_child], parent_lazy_value_to_push);
            apply_op(tree[left_child], parent_lazy_value_to_push, L, mid);

            lazy[right_child] = combine_op(lazy[right_child], parent_lazy_value_to_push);
            apply_op(tree[right_child], parent_lazy_value_to_push, mid + 1, R);

            lazy[node] = no_lazy_val;
        }
    }

    void pull(int node) {
        if (2 * node + 1 < tree.size()) {
            tree[node] = merge_op(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void build_internal(int node, int L, int R) {
        lazy[node] = no_lazy_val;
        if (L == R) {
            tree[node] = build_op(L);
            return;
        }
        int mid = L + (R - L) / 2;
        build_internal(2 * node, L, mid);
        build_internal(2 * node + 1, mid + 1, R);
        pull(node);
    }

    void update_internal(int node, int L, int R, int i, int j, const T_Lazy& update) {
        if (L > R || L > j || R < i)
            return;
        if (L >= i && R <= j) {
            lazy[node] = combine_op(lazy[node], update);
            apply_op(tree[node], update, L, R);
            return;
        }

        push(node, L, R);
        int mid = L + (R - L) / 2;
        update_internal(2 * node, L, mid, i, j, update);
        update_internal(2 * node + 1, mid + 1, R, i, j, update);
        pull(node);
    }

    T_Node query_internal(int node, int L, int R, int i, int j) {
        if (L > R || L > j || R < i) {
            return identity_node_val;
        }
        if (L >= i && R <= j) {
            return tree[node];
        }

        push(node, L, R);
        int mid = L + (R - L) / 2;

        T_Node p1 = query_internal(2 * node, L, mid, i, j);
        T_Node p2 = query_internal(2 * node + 1, mid + 1, R, i, j);

        return merge_op(p1, p2);
    }

   public:
    SegmentTree(int n, T_Lazy no_l, T_Node identity_n, Merger m, Applier a, Combiner c, Builder b) : N(n), no_lazy_val(no_l), identity_node_val(identity_n), merge_op(m), apply_op(a), combine_op(c), build_op(b) {
        tree.resize(4 * N + 5);
        lazy.resize(4 * N + 5);
        if (N > 0) {
            build_internal(1, 0, N - 1);
        }
    }

    void update(int i, int j, const T_Lazy& u) {
        if (N == 0 || i > j || i < 0 || j >= N)
            return;
        update_internal(1, 0, N - 1, i, j, u);
    }

    T_Node query(int i, int j) {
        if (N == 0 || i > j || i < 0 || j >= N)
            return identity_node_val;
        return query_internal(1, 0, N - 1, i, j);
    }
};

vector<long long> a;

void solve() {
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for(auto& x : a) cin >> x;

    auto merge = [](const long long& a, const long long& b) -> long long { 
        return a + b; 
    };

    auto apply = [](long long& node, const long long& lazy_val, int L, int R) { 
        node += lazy_val;
    };

    auto combine = [](const long long& old_lazy, const long long& new_lazy) { 
        return old_lazy + new_lazy; 
    };

    auto build = [](int idx) { 
        return a[idx]; 
    };

    SegmentTree<long long, long long> st(
        n,
        0LL,  // no lazy value
        0LL,  // identity for sum
        merge,
        apply,
        combine,
        build
    );

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int i;
            cin >> i;
            long long val = st.query(i, i);
            cout << val << '\n';
            st.update(i, i, -val);  // set to 0 by subtracting current value
        } else if(type == 2) {
            int i;
            long long v;
            cin >> i >> v;
            st.update(i, i, v);
        } else {
            int i, j;
            cin >> i >> j;
            cout << st.query(i, j) << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        a.clear();
        cout << "Case " << i << ":\n";
        solve();
    }

    return 0;
}

