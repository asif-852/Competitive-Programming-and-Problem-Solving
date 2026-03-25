
#include <bits/stdc++.h>
using namespace std;

/*
Binary Indexed Tree (BIT) / Fenwick Tree
Supports point updates and prefix sum queries in O(log n) time.
Range updates and range queries in O(log n) time.

Original source: https://github.com/ShahjalalShohag/code-library
*/
 
struct BIT {
    vector<long long> M, A;
    BIT(int n) {
        init(n);
    }
    void init(int n) {
        M.resize(n + 1);
        A.resize(n + 1);
    }
    void update(int i, long long mul, long long add) {
        while (i < M.size()) {
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

void solve() {
    // Example usage of BIT
    BIT bit(10);
    bit.rangeUpdate(2, 5, 3);
    cout << bit.rangeQuery(3, 4) << '\n';
    // Output: 9 (3 from the range update for both indices 3 and 4)
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
