
#include <bits/stdc++.h>
using namespace std;

vector<tuple<long double,long double,long double>> v;

long double distance(long double x1, long double y1, long double x2, long double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool is_occupied(long double x, long double y) {
    bool ok = false;
    for(auto u : v) {
        long double r = get<2>(u);
        ok |= ( r >= distance(get<0>(u), get<1>(u), x, y) );
    }
    return ok;
}

void solve() {

    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> get<0>(v[i]) >> get<1>(v[i]) >> get<2>(v[i]);
    }
    int cnt = 0;
    for(int i = 0; i <= 3000; i++) {
        for(int j = 0; j <= 3000; j++) {
            long double x = i / 3000.0, y = j / 3000.0;
            cnt += (is_occupied(x, y));
        }
    }

    cout << (long double) cnt * 100 / 9000000.0 << '\n';

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