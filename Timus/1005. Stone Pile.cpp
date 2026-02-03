
#include <bits/stdc++.h>
using namespace std;

int PartitionRecursive(vector<int> &num, int currentIndex, int sum1, int sum2) {
    if(currentIndex == num.size()) return abs(sum1 - sum2);

    int diff1 = PartitionRecursive(num, currentIndex + 1, sum1 + num[currentIndex], sum2);
    int diff2 = PartitionRecursive(num, currentIndex + 1, sum1, sum2 + num[currentIndex]);

    return min(diff1, diff2);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << PartitionRecursive(v, 0, 0, 0) << '\n';
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