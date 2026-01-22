
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 1;
vector<long long> ans(N), phi(N);
 
void solve() {
    int n;
    cin >> n;
    cout << ans[n] << '\n';
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    iota(phi.begin(), phi.end(), 0);
    for(int i = 1; i < N; i++) {
        for(int j = 2 * i; j < N; j += i) {
            phi[j] -= phi[i];
        }
    }
 
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            ans[j] += i * phi[i];
        }
    }
    for(int i = 1; i < N; i++) {
        ans[i] += 1;
        ans[i] *= i;
        ans[i] /= 2;
    }
 
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
 
    return 0;
}