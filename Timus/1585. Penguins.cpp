
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    vector<string> v = {"Emperor Penguin", "Little Penguin", "Macaroni Penguin"};
    vector<int> u = {0, 0, 0};
    int n;
    cin >> n;
    while(n--) {
        char c;
        cin >> c;
        string s;
        getline(cin, s);
        s = c + s;
        if(s == v[0]) u[0]++;
        else if(s == v[1]) u[1]++;
        else if(s == v[2]) u[2]++;
    }
    int pos = max_element(u.begin(), u.end()) - u.begin();
    cout << v[pos] << '\n';
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