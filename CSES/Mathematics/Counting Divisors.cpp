
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000000;
int divisor_count[N + 1];

void solve() {
    int n;
    cin >> n;
    cout << divisor_count[n] << '\n';
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            divisor_count[j]++;
        }
    }

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}