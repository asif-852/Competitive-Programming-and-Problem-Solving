
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    vector<stack<int>> v(n);
    int val = 1;
    for(int i = 1, j = 1; j < 2 * n; i++, j++) {
        int k = min(i, n);

        for(int l = 0; l < k; l++) {
            if(v[l].size() < n) {
                v[l].push(val);
                val++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        while(!v[i].empty()) {
            cout << v[i].top() << " ";
            v[i].pop();
        }
        cout << '\n';
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