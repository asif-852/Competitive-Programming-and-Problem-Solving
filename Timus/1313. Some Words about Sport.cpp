
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    vector<queue<int>> v(n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            v[i].push(x);
        }
    }

    for(int i = 1, j = 1; j < 2 * n; i++, j++) {
        int k = min(i, n);

        while(k) {
            if(!v[k].empty()) {
                cout << v[k].front() << " ";
                v[k].pop();
            }
            k--;
        }
    }
    cout << '\n';
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