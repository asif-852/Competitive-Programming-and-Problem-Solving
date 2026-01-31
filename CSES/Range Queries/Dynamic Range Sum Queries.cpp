
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

void solve() {
    int n, q;
    cin >> n >> q;
    BIT bit(n);
    vector<long long> current_values(n);

    for(int i = 0; i < n; i++) {
        long long val;
        cin >> val;
        current_values[i] = val;
        bit.rangeUpdate(i, i, val);
    }

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k;
            long long u;
            cin >> k >> u;
            int idx = k - 1;
            long long diff = u - current_values[idx];
            current_values[idx] = u;
            bit.rangeUpdate(idx, idx, diff);
        } else {
            int a, b;
            cin >> a >> b;            
            cout << bit.rangeQuery(a - 1, b - 1) << '\n';
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