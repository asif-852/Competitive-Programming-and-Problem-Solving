
#include <bits/stdc++.h>
using namespace std;
 
void get_divisors(vector<long long>& v, long long n) {
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            v.push_back(i);
            if(i != n / i) {
                v.push_back(n / i);
            }
        }
    }
}

void solve() {
    long long a, b;
    cin >> a >> b;
    long long GCD = __gcd(a, b);
    vector<long long> v;
    get_divisors(v, GCD);
    cout << v.size() << '\n';
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}