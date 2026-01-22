
// Approach 1: Fermat's Little Theorem based Primality Test 
#include <bits/stdc++.h>
using namespace std;
 
using u128 = __uint128_t;
 
long long binpower(long long base, long long e, long long mod) {
    long long result = 1;
    base %= mod;
    while (e) {
        if (e & 1) result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
 
bool probablyPrimeFermat(long long n, int iter = 5) {
    if (n < 4) return (n == 2 || n == 3);
 
    for (int i = 0; i < iter; i++) {
        long long a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1) return false;
    }
    return true;
}
 
void solve() {
    long long n;
    cin >> n;
    cout << (probablyPrimeFermat(n) ? "YES" : "NO") << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));
 
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}

// Approach 2: Miller-Rabin Primality Test

/*

#include <bits/stdc++.h>
using namespace std;
 
using u128 = __uint128_t;
 
long long binpower(long long base, long long e, long long mod) {
    long long result = 1;
    base %= mod;
    while (e) {
        if (e & 1) result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
 
bool check_composite(long long n, long long a, long long d, int s) {
    long long x = binpower(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
};
 
bool MillerRabin(long long n, int iter = 5) {
    if (n < 4) return (n == 2 || n == 3);
 
    int s = 0;
    long long d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
 
    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s)) return false;
    }
    return true;
}
 
void solve() {
 
    long long n;
    cin >> n;
    cout << (MillerRabin(n) ? "YES" : "NO") << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));
 
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}
 

*/