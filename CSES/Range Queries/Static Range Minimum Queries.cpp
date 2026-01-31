
#include <bits/stdc++.h>
using namespace std;

// Template for Sparse Table (idempotent functions)

/*
Usage example:
auto func = [](int x, int y) { use operations like min / max / gcd / and / or etc. };
SparseTable<int, decltype(func)> st(a, func);
*/

template <typename T, typename F>
class SparseTable {
   public:
    int n;
    vector<vector<T>> mat;  // mat[j][i] stores the result for the interval of length 2^j starting at i
    F func;

    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
}; 



void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto min_func = [](int x, int y) { return min(x, y); };
    SparseTable<int, decltype(min_func)> st(a, min_func);

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        st.get(l - 1, r - 1); 
        cout << st.get(l - 1, r - 1) << '\n';
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