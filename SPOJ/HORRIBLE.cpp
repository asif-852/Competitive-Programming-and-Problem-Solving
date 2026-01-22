
#include <bits/stdc++.h>
using namespace std;
 
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
    int n, q;
    cin >> n >> q;
    BIT bit(n + 1);
 
    while(q--) {
        int type;
        cin >> type;
        if(type == 0) {
            long long l, r, x;
            cin >> l >> r >> x;
            bit.rangeUpdate(l, r, x);
        }
        else {
            long long l, r;
            cin >> l >> r;
            cout << bit.rangeQuery(l, r) << '\n';
        }
    }
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
 
    return 0;
} 
