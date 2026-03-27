
#include <bits/stdc++.h>
using namespace std;

/*
Sparse Table (idempotent functions)
Supports static range queries in O(1) time after O(n log n) preprocessing.
Works for any idempotent function (min, max, gcd, lcm, bitwise and, bitwise or, etc.).

Original source: https://github.com/the-tourist/algo
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
    // Example usage of Sparse Table
    vector<int> a = {1, 3, 4, 8, 7};
    auto func = [](int x, int y) { 
        // use operations like min / max / gcd / and / or etc. 
        return min(x, y);  // Example: for range minimum query
    };
    SparseTable<int, decltype(func)> st(a, func);
    cout << st.get(1, 3) << '\n'; // Output: 3 (minimum in the range [1, 3])
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