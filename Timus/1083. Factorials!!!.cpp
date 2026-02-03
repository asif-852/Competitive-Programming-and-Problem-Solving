
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a;
    string str;
    cin >> a >> str;

    int i = a;
    long long fact = 1;
    while(i >= 1) {
        fact = fact * i;
        i = i - (int)(str.length() - 1);
    }

    cout << fact << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}