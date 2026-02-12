

/*

// Approach 1: Hashing and BIT
// Version 1: Single Hasing with BIT
// Time : 210 ms

*/

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
};

struct string_Hash {
    vector<int> primes = {10007, 12433, 10009, 12601, 10039, 12641, 10061, 12671, 34273,
                          12721, 10427, 13339, 35353, 13487, 67789, 13591, 68743, 13789,
                          72271, 28229, 76157, 29437, 80387, 30313, 81181, 30313, 84499,
                          13879, 86269, 25679, 89051, 26321, 90709, 26681, 98081, 27277};
    int P;
    vector<int> mods = {1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103,
        1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271,
        1000000289, 1000000297, 1000000321, 1000000349, 1000000363, 1000000403,
        1000000409, 1000000411, 1000000427, 1000000433, 1000000439, 1000000447,
        1000000453, 1000000459, 1000000483, 1000000513, 1000000531, 1000000579,
        1000000607, 1000000613, 1000000637, 1000000663, 1000000711, 1000000753};

    int mod;
    int invp, n;
    vector<int> pw, invpw, pref; // Using single hashing
    string s;

    string_Hash() {}
    string_Hash(string s, int idx) {
        init(s, idx);
    }

    void init(string s, int idx) {
        this->s = s;
        n = s.size();
        P = primes[idx];
        mod = mods[idx];
        pw.resize(n);
        invpw.resize(n);
        pref.resize(n);
        precal();
        build();
    }

    int binpower(long long base, long long e, int mod) {
        int ans = 1 % mod;
        base %= mod;
        if (base < 0) base += mod;

        while (e) {
            if (e & 1) ans = (long long)ans * base % mod;
            base = (long long)base * base % mod;
            e >>= 1;
        }
        return ans;
    }

    void precal() {
        pw[0] = P;

        for (int i = 1; i < n; i++) {
            pw[i] = 1LL * pw[i - 1] * P % mod;
        }

        invp = binpower(P, mod - 2, mod);

        invpw[0] = invp;

        for (int i = 1; i < n; i++) {
            invpw[i] = 1LL * invpw[i - 1] * invp % mod;
        }
    }

    void build() {
        for (int i = 0; i < n; i++) {
            pref[i] = 1LL * s[i] * pw[i] % mod;

            if (i) {
                pref[i] = (pref[i] + pref[i - 1]) % mod;
            }
        }
    }

    int substringHash(int i, int j) {
        assert(i <= j);

        int hs = pref[j];
        if (i) {
            hs = (hs - pref[i - 1] + mod) % mod;
        }
        hs = 1LL * hs * invpw[i] % mod;
        if(hs < 0) hs += mod;

        return hs;
    }

    int fullStringHash() {
        return substringHash(0, n - 1);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int idx = ((rand() % 36) + 36) % 36;
    string_Hash H(s, idx);
    int mod = H.mod;

    // 2 BITs: forward and reverse
    BIT fwd(n), rev(n);

    // Initialize: position i stores s[i] * pw[i] (forward) or s[i] * pw[n-1-i] (reverse)
    for(int i = 0; i < n; i++) {
        fwd.rangeUpdate(i, i, 1LL * s[i] * H.pw[i] % mod);
        rev.rangeUpdate(i, i, 1LL * s[i] * H.pw[n - 1 - i] % mod);
    }

    while(m--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k; char x;
            cin >> k >> x;
            k--;
            long long delta;

            delta = 1LL * (x - s[k]) * H.pw[k] % mod;
            fwd.rangeUpdate(k, k, delta);

            delta = 1LL * (x - s[k]) * H.pw[n - 1 - k] % mod;
            rev.rangeUpdate(k, k, delta);

            s[k] = x;
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--;

            long long fh = (fwd.rangeQuery(a, b) % mod + mod) % mod;
            fh = 1LL * fh * H.invpw[a] % mod;

            long long rh = (rev.rangeQuery(a, b) % mod + mod) % mod;
            rh = 1LL * rh * H.invpw[n - 1 - b] % mod;

            cout << (fh == rh ? "YES" : "NO") << '\n';
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







/*

// Approach 1: Hashing and BIT
// Version 2: Double Hasing with BIT
// Time : 410 ms

*/

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
};

struct string_Hash {
    vector<int> primes = {10007, 12433, 10009, 12601, 10039, 12641, 10061, 12671, 34273,
                          12721, 10427, 13339, 35353, 13487, 67789, 13591, 68743, 13789,
                          72271, 28229, 76157, 29437, 80387, 30313, 81181, 30313, 84499,
                          13879, 86269, 25679, 89051, 26321, 90709, 26681, 98081, 27277};
    int P1, P2;
    vector<int> mods = {1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103,
        1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271,
        1000000289, 1000000297, 1000000321, 1000000349, 1000000363, 1000000403,
        1000000409, 1000000411, 1000000427, 1000000433, 1000000439, 1000000447,
        1000000453, 1000000459, 1000000483, 1000000513, 1000000531, 1000000579,
        1000000607, 1000000613, 1000000637, 1000000663, 1000000711, 1000000753};

    int mod1, mod2;
    int invp1, invp2, n;
    vector<int> pw1, pw2, invpw1, invpw2, pref1, pref2; // Using separate vectors for double hashing
    string s;

    string_Hash() {}
    string_Hash(string s, int idx1, int idx2) {
        init(s, idx1, idx2);
    }

    void init(string s, int idx1, int idx2) {
        this->s = s;
        n = s.size();
        P1 = primes[idx1];
        P2 = primes[idx2];
        mod1 = mods[idx1];
        mod2 = mods[idx2];
        pw1.resize(n);
        pw2.resize(n);
        invpw1.resize(n);
        invpw2.resize(n);
        pref1.resize(n);
        pref2.resize(n);
        precal();
        build();
    }

    int binpower(long long base, long long e, int mod) {
        int ans = 1 % mod;
        base %= mod;
        if (base < 0) base += mod;

        while (e) {
            if (e & 1) ans = (long long)ans * base % mod;
            base = (long long)base * base % mod;
            e >>= 1;
        }
        return ans;
    }

    void precal() {
        pw1[0] = P1; pw2[0] = P2;

        for (int i = 1; i < n; i++) {
            pw1[i] = 1LL * pw1[i - 1] * P1 % mod1;
            pw2[i] = 1LL * pw2[i - 1] * P2 % mod2;
        }

        invp1 = binpower(P1, mod1 - 2, mod1);
        invp2 = binpower(P2, mod2 - 2, mod2);

        invpw1[0] = invp1; invpw2[0] = invp2;

        for (int i = 1; i < n; i++) {
            invpw1[i] = 1LL * invpw1[i - 1] * invp1 % mod1;
            invpw2[i] = 1LL * invpw2[i - 1] * invp2 % mod2;
        }
    }

    void build() {
        for (int i = 0; i < n; i++) {
            pref1[i] = 1LL * s[i] * pw1[i] % mod1;
            pref2[i] = 1LL * s[i] * pw2[i] % mod2;

            if (i) {
                pref1[i] = (pref1[i] + pref1[i - 1]) % mod1;
                pref2[i] = (pref2[i] + pref2[i - 1]) % mod2;
            }
        }
    }

    pair<int, int> substringHash(int i, int j) {
        assert(i <= j);

        int hs1 = pref1[j];
        if (i) {
            hs1 = (hs1 - pref1[i - 1] + mod1) % mod1;
        }
        hs1 = 1LL * hs1 * invpw1[i] % mod1;
        if(hs1 < 0) hs1 += mod1;

        int hs2 = pref2[j];
        if (i) {
            hs2 = (hs2 - pref2[i - 1] + mod2) % mod2;
        }
        hs2 = 1LL * hs2 * invpw2[i] % mod2;
        if(hs2 < 0) hs2 += mod2;

        return {hs1, hs2};
    }

    pair<int, int> fullStringHash() {
        return substringHash(0, n - 1);
    }
};

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int idx1 = 0, idx2 = 0;
    while(idx1 == idx2) {
        idx1 = ((rand() % 36) + 36) % 36;
        idx2 = ((rand() % 36) + 36) % 36;
    }
    string_Hash H(s, idx1, idx2);
    int mod1 = H.mod1, mod2 = H.mod2;

    // 4 BITs: forward and reverse, for each of the two hash functions
    BIT fwd1(n), fwd2(n), rev1(n), rev2(n);

    // Initialize: position i stores s[i] * pw[i] (forward) or s[i] * pw[n-1-i] (reverse)
    for(int i = 0; i < n; i++) {
        fwd1.rangeUpdate(i, i, 1LL * s[i] * H.pw1[i] % mod1);
        fwd2.rangeUpdate(i, i, 1LL * s[i] * H.pw2[i] % mod2);
        rev1.rangeUpdate(i, i, 1LL * s[i] * H.pw1[n - 1 - i] % mod1);
        rev2.rangeUpdate(i, i, 1LL * s[i] * H.pw2[n - 1 - i] % mod2);
    }

    while(m--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k; char x;
            cin >> k >> x;
            k--;
            long long delta;

            delta = 1LL * (x - s[k]) * H.pw1[k] % mod1;
            fwd1.rangeUpdate(k, k, delta);

            delta = 1LL * (x - s[k]) * H.pw2[k] % mod2;
            fwd2.rangeUpdate(k, k, delta);

            delta = 1LL * (x - s[k]) * H.pw1[n - 1 - k] % mod1;
            rev1.rangeUpdate(k, k, delta);

            delta = 1LL * (x - s[k]) * H.pw2[n - 1 - k] % mod2;
            rev2.rangeUpdate(k, k, delta);

            s[k] = x;
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--;

            long long fh1 = (fwd1.rangeQuery(a, b) % mod1 + mod1) % mod1;
            fh1 = 1LL * fh1 * H.invpw1[a] % mod1;

            long long fh2 = (fwd2.rangeQuery(a, b) % mod2 + mod2) % mod2;
            fh2 = 1LL * fh2 * H.invpw2[a] % mod2;

            long long rh1 = (rev1.rangeQuery(a, b) % mod1 + mod1) % mod1;
            rh1 = 1LL * rh1 * H.invpw1[n - 1 - b] % mod1;

            long long rh2 = (rev2.rangeQuery(a, b) % mod2 + mod2) % mod2;
            rh2 = 1LL * rh2 * H.invpw2[n - 1 - b] % mod2;

            cout << (fh1 == rh1 && fh2 == rh2 ? "YES" : "NO") << '\n';
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

*/







/*

// Approach 2: Double Hashing and Segment Tree
// Time : 990 ms

*/


/*
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
        if (L > R || L > j || R < i) return;
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
    SegmentTree(int n, T_Lazy no_l, T_Node identity_n,
                Merger m, Applier a, Combiner c, Builder b)
        : N(n), no_lazy_val(no_l), identity_node_val(identity_n),
          merge_op(m), apply_op(a), combine_op(c), build_op(b) {
        tree.resize(4 * N + 5);
        lazy.resize(4 * N + 5);
        if (N > 0) {
            build_internal(1, 0, N - 1);
        }
    }

    void update(int i, int j, const T_Lazy& u) {
        if (N == 0 || i > j || i < 0 || j >= N) return;
        update_internal(1, 0, N - 1, i, j, u);
    }

    T_Node query(int i, int j) {
        if (N == 0 || i > j || i < 0 || j >= N) return identity_node_val;
        return query_internal(1, 0, N - 1, i, j);
    }
};

struct string_Hash {
    vector<int> primes = {10007, 12433, 10009, 12601, 10039, 12641, 10061, 12671, 34273,
                          12721, 10427, 13339, 35353, 13487, 67789, 13591, 68743, 13789,
                          72271, 28229, 76157, 29437, 80387, 30313, 81181, 30313, 84499,
                          13879, 86269, 25679, 89051, 26321, 90709, 26681, 98081, 27277};
    int P1, P2;
    vector<int> mods = {1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103,
        1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271,
        1000000289, 1000000297, 1000000321, 1000000349, 1000000363, 1000000403,
        1000000409, 1000000411, 1000000427, 1000000433, 1000000439, 1000000447,
        1000000453, 1000000459, 1000000483, 1000000513, 1000000531, 1000000579,
        1000000607, 1000000613, 1000000637, 1000000663, 1000000711, 1000000753};

    int mod1, mod2;
    int invp1, invp2, n;
    vector<int> pw1, pw2, invpw1, invpw2, pref1, pref2; // Using separate vectors for double hashing
    string s;

    string_Hash() {}
    string_Hash(string s, int idx1, int idx2) {
        init(s, idx1, idx2);
    }

    void init(string s, int idx1, int idx2) {
        this->s = s;
        n = s.size();
        P1 = primes[idx1];
        P2 = primes[idx2];
        mod1 = mods[idx1];
        mod2 = mods[idx2];
        pw1.resize(n);
        pw2.resize(n);
        invpw1.resize(n);
        invpw2.resize(n);
        pref1.resize(n);
        pref2.resize(n);
        precal();
        build();
    }

    int binpower(long long base, long long e, int mod) {
        int ans = 1 % mod;
        base %= mod;
        if (base < 0) base += mod;

        while (e) {
            if (e & 1) ans = (long long)ans * base % mod;
            base = (long long)base * base % mod;
            e >>= 1;
        }
        return ans;
    }

    void precal() {
        pw1[0] = P1; pw2[0] = P2;

        for (int i = 1; i < n; i++) {
            pw1[i] = 1LL * pw1[i - 1] * P1 % mod1;
            pw2[i] = 1LL * pw2[i - 1] * P2 % mod2;
        }

        invp1 = binpower(P1, mod1 - 2, mod1);
        invp2 = binpower(P2, mod2 - 2, mod2);

        invpw1[0] = invp1; invpw2[0] = invp2;

        for (int i = 1; i < n; i++) {
            invpw1[i] = 1LL * invpw1[i - 1] * invp1 % mod1;
            invpw2[i] = 1LL * invpw2[i - 1] * invp2 % mod2;
        }
    }

    void build() {
        for (int i = 0; i < n; i++) {
            pref1[i] = 1LL * s[i] * pw1[i] % mod1;
            pref2[i] = 1LL * s[i] * pw2[i] % mod2;

            if (i) {
                pref1[i] = (pref1[i] + pref1[i - 1]) % mod1;
                pref2[i] = (pref2[i] + pref2[i - 1]) % mod2;
            }
        }
    }

    pair<int, int> substringHash(int i, int j) {
        assert(i <= j);

        int hs1 = pref1[j];
        if (i) {
            hs1 = (hs1 - pref1[i - 1] + mod1) % mod1;
        }
        hs1 = 1LL * hs1 * invpw1[i] % mod1;
        if(hs1 < 0) hs1 += mod1;

        int hs2 = pref2[j];
        if (i) {
            hs2 = (hs2 - pref2[i - 1] + mod2) % mod2;
        }
        hs2 = 1LL * hs2 * invpw2[i] % mod2;
        if(hs2 < 0) hs2 += mod2;

        return {hs1, hs2};
    }

    pair<int, int> fullStringHash() {
        return substringHash(0, n - 1);
    }
};

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int idx1 = 0, idx2 = 0;
    while(idx1 == idx2) {
        idx1 = ((rand() % 36) + 36) % 36;
        idx2 = ((rand() % 36) + 36) % 36;
    }
    string_Hash H(s, idx1, idx2);
    int mod1 = H.mod1, mod2 = H.mod2;

    using Node = pair<long long, long long>;
    using Lazy = pair<long long, long long>;

    auto merge = [&](const Node& a, const Node& b) -> Node {
        return {(a.first + b.first) % mod1, (a.second + b.second) % mod2};
    };
    auto apply = [](Node& node, const Lazy& lz, int L, int R) {
        node = {lz.first, lz.second};
    };
    auto combine = [](const Lazy& old_lz, const Lazy& new_lz) -> Lazy {
        return new_lz;
    };

    // Forward tree: position i stores (s[i] * pw1[i] % mod1, s[i] * pw2[i] % mod2)
    auto buildFwd = [&](int i) -> Node {
        return {1LL * s[i] * H.pw1[i] % mod1, 1LL * s[i] * H.pw2[i] % mod2};
    };

    // Reverse tree: position i stores (s[i] * pw1[n-1-i] % mod1, s[i] * pw2[n-1-i] % mod2)
    auto buildRev = [&](int i) -> Node {
        return {1LL * s[i] * H.pw1[n - 1 - i] % mod1, 1LL * s[i] * H.pw2[n - 1 - i] % mod2};
    };

    SegmentTree<Node, Lazy> fwd(n, {-1, -1}, {0, 0}, merge, apply, combine, buildFwd);
    SegmentTree<Node, Lazy> rev(n, {-1, -1}, {0, 0}, merge, apply, combine, buildRev);

    while(m--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k; char x;
            cin >> k >> x;
            k--;
            s[k] = x;
            fwd.update(k, k, {1LL * x * H.pw1[k] % mod1, 1LL * x * H.pw2[k] % mod2});
            rev.update(k, k, {1LL * x * H.pw1[n - 1 - k] % mod1, 1LL * x * H.pw2[n - 1 - k] % mod2});
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--;

            auto [fh1, fh2] = fwd.query(a, b);
            fh1 = 1LL * fh1 * H.invpw1[a] % mod1;
            fh2 = 1LL * fh2 * H.invpw2[a] % mod2;

            auto [rh1, rh2] = rev.query(a, b);
            rh1 = 1LL * rh1 * H.invpw1[n - 1 - b] % mod1;
            rh2 = 1LL * rh2 * H.invpw2[n - 1 - b] % mod2;

            cout << (fh1 == rh1 && fh2 == rh2 ? "YES" : "NO") << '\n';
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
*/