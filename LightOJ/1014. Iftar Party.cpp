
#include <bits/stdc++.h>
using namespace std;

void get_divisors(vector<long long> &v, long long n) {
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            v.push_back(i);
            if((n / i) != i) {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
}

void solve() {

    long long p, l;
    cin >> p >> l;
    if(l * 2 >= p) {
        cout << "impossible" << '\n';
        return;
    }
    vector<long long> divisors;
    get_divisors(divisors, p - l);
    for(int i = 0; i < (int)divisors.size(); i++) {
        if(divisors[i] <= l) continue;
        cout << divisors[i] << " \n"[i == (int)divisors.size() - 1];
    }


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