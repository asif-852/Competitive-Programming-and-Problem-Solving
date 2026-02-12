
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int cnt[N + 1];
int multiples[N + 1];

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
 
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            if(cnt[j]) {
                multiples[i] += cnt[j];
            }
        }
    }
 
    int ans = 1;
    for(int i = N; i >= 1; i--) {
        if(multiples[i] > 1) {
            ans = i;
            break;
        }
    }
 
    cout << ans << '\n';
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