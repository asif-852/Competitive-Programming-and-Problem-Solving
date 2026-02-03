
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int a, b, c, min;
    cin >> a >> b >> c;
    min = a + b + c;
    if(a + b - c < min) min = a + b - c;
    if(a - b + c < min) min = a - b + c;
    if(a - b - c < min) min = a - b - c;
    if(a - b + c < min) min = a - b + c;
    if(a - b * c < min) min = a - b * c;
    if(a * b * c < min) min = a * b * c;
    if(a * b + c < min) min = a * b + c;
    if(a * b - c < min) min = a * b - c;
    cout << min << '\n';
    
    // easiest: cout << a - b * c << '\n';
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