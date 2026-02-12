
#include <bits/stdc++.h>
using namespace std;

long long countSetBits(long long n) {
    n++;
    long long powerOf2 = 2;
    long long cnt = n / 2;
 
    while(powerOf2 <= n) {
        long long totalPairs = n / powerOf2;
        cnt += (totalPairs / 2) * powerOf2;
        cnt += (totalPairs & 1) ? (n % powerOf2) : 0;
        powerOf2 <<= 1;
    }
 
    return cnt;
}

void solve() {
    long long n;
    cin >> n;
    cout << countSetBits(n) << '\n';
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