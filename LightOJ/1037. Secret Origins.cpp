
#include <bits/stdc++.h>
using namespace std;

string dec_to_bin(long long n) {
    string s = "";
    while(n) {
        s += char(n % 2 + '0');
        n /= 2;
    }
    for(int i = s.size(); i < 32; i++) {
        s += '0';
    }
    reverse(s.begin(), s.end());

    return s;
}

long long bin_to_dec(string s) {
    long long n = 0;
    for(int i = 0; i < 32; i++) {
        n <<= 1;
        n += s[i] - '0';
    }

    return n;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        long long n;
        cin >> n;
        string bin = dec_to_bin(n);
        next_permutation(bin.begin(), bin.end());
        cout << "Case " << i << ": " << bin_to_dec(bin) << '\n';
    }

    return 0;
}