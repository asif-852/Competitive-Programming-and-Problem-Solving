
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
    vector<int> v(n);
    vector<int> inputs;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inputs.push_back(x);
        v[i] = x;
    }
    vector<tuple<char, int, int>> queries;
    for(int i = 0; i < q; i++) {
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        queries.push_back({c, a, b});
        inputs.push_back(b);
        if(c == '?') {
            inputs.push_back(a);
        }
    }
    sort(inputs.begin(), inputs.end());
	inputs.erase(unique(inputs.begin(), inputs.end()), inputs.end());
    map<int, int> compressed;
    int id = 1;
    for(auto u : inputs) {
        compressed[u] = id++;
    }
    for(auto& u : v) {
        u = compressed[u];
    }
    for(auto& [c, a, b] : queries) {
        b = compressed[b];
        if(c == '?') {
            a = compressed[a];
        }
    }
 
    BIT tree(id + 1);
    for(int i = 0; i < n; i++) {
        tree.rangeUpdate(v[i], v[i], 1);
    }
    for(auto [c, a, b] : queries) {
        if(c == '?') {
            cout << tree.rangeQuery(a, b) << '\n';
        } else {
            int pos = --a;
            tree.rangeUpdate(v[pos], v[pos], -1);
            v[pos] = b;
            tree.rangeUpdate(b, b, 1);
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
 
