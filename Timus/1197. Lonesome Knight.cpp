
#include <bits/stdc++.h>
using namespace std;

bool inside_boundary(int i, int j) {
    return (1 <= i && i <= 8 && 1 <= j  && j <= 8);
}

void solve() {
    int j;
    char c;
    cin >> c >> j;
    int i;
    i = c - 96;
    int cnt = 0;
    for(auto [di, dj] : {pair{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}}) {
        cnt += inside_boundary(i + di, j + dj);
    }

    cout << cnt << '\n';
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