#include <bits/stdc++.h>
using namespace std;
 
long long PartitionRecursive(vector<long long> &num, long long currentIndex, long long sum1, long long sum2) {
    if(currentIndex == num.size()) return abs(sum1 - sum2);
 
    long long diff1 = PartitionRecursive(num, currentIndex + 1, sum1 + num[currentIndex], sum2);
    long long diff2 = PartitionRecursive(num, currentIndex + 1, sum1, sum2 + num[currentIndex]);
 
    return min(diff1, diff2);
}
 
void solve() {
 
    long long n;
    cin >> n;
    vector<long long> v(n);
    for(auto &x : v) cin >> x;
    cout << PartitionRecursive(v, 0, 0, 0) << '\n';
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}