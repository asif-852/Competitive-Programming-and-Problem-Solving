
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    double a, b;
    string s1;
    cin >> a;
    cin >> s1;
    cin >> b;
    double r, theta, s;
    r = sqrt(a * a + b * b) / 2.0;
    theta = acos((2.0 * r * r - b * b) / (2.0 * r * r));
    s = r * theta;
    double x = 400.0 / (2 * a + 2 * s);
    cout << fixed << setprecision(8) << a * x << " " << b * x << '\n';
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}