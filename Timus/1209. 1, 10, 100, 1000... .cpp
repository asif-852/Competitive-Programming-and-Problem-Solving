
#include <bits/stdc++.h>
using namespace std;
 
vector<long long> exist1;

void solve() {
    int n;
    cin >> n;
    cout << ((binary_search(exist1.begin(), exist1.end(), n)) ? "1 " : "0 ");
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long cnt = 1, i = 1;
    while(i <= 2147483647) {
        exist1.push_back(i);
        i += cnt;
        cnt++;
    }

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}