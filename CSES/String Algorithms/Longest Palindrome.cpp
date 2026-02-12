
#include <bits/stdc++.h>
using namespace std;
 
 
constexpr int mod = 1000000711;
 
struct string_Hash {
    vector<int> primes = {10007, 12433, 10009, 12601, 10039, 12641, 10061, 12671, 34273,
                          12721, 10427, 13339, 35353, 13487, 67789, 13591, 68743, 13789,
                          72271, 28229, 76157, 29437, 80387, 30313, 81181, 30313, 84499,
                          13879, 86269, 25679, 89051, 26321, 90709, 26681, 98081, 27277};
    int P;
    vector<int> mods = {1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103,
        1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271,
        1000000289, 1000000297, 1000000321, 1000000349, 1000000363, 1000000403,
        1000000409, 1000000411, 1000000427, 1000000433, 1000000439, 1000000447,
        1000000453, 1000000459, 1000000483, 1000000513, 1000000531, 1000000579,
        1000000607, 1000000613, 1000000637, 1000000663, 1000000711, 1000000753};
 
    
    int invp, n;
    vector<int> pw, invpw, pref;
    string s;
 
    string_Hash() {}
    string_Hash(string s, int idx) {
        init(s, idx);
    }
 
    void init(string s, int idx) {
        this->s = s;
        n = s.size();
        P = primes[idx];
        //mod = mods[idx];
        pw.resize(n);
        invpw.resize(n);
        pref.resize(n);
        precal();
        build();
    }
 
    int binpower(long long base, long long e, int mod) {
        int ans = 1 % mod;
        base %= mod;
        if (base < 0) base += mod;
 
        while (e) {
            if (e & 1) ans = (long long)ans * base % mod;
            base = (long long)base * base % mod;
            e >>= 1;
        }
        return ans;
    }
 
    void precal() {
        pw[0] = P;
 
        for (int i = 1; i < n; i++) {
            pw[i] = 1LL * pw[i - 1] * P % mod;
        }
 
        invp = binpower(P, mod - 2, mod);
 
        invpw[0] = invp;
 
        for (int i = 1; i < n; i++) {
            invpw[i] = 1LL * invpw[i - 1] * invp % mod;
        }
    }
 
    void build() {
        for (int i = 0; i < n; i++) {
            pref[i] = 1LL * s[i] * pw[i] % mod;
 
            if (i) {
                pref[i] = (pref[i] + pref[i - 1]) % mod;
            }
        }
    }
 
    int substringHash(int i, int j) {
        assert(i <= j);
 
        int hs = pref[j];
        if (i) {
            hs = (hs - pref[i - 1] + mod) % mod;
        }
        hs = 1LL * hs * invpw[i] % mod;
        if(hs < 0) hs += mod;
 
        return hs;
    }
 
    int fullStringHash() {
        return substringHash(0, n - 1);
    }
};
 
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    int idx = ((rand() % 36) + 36) % 36;
    
    string_Hash hs(s, idx);
    string_Hash hr(rev, idx);
    
    // For reversed string: substring [i, j] in original corresponds to [n - 1 - j, n - 1 - i] in reversed
    // A substring s[l..r] is a palindrome if hash(s[l..r]) == hash(rev[n - 1 - r..n - 1 - l])
    
    int bestLen = 1, bestStart = 0;
    
    // Check odd length palindromes centered at i
    for(int i = 0; i < n; i++) {
        int lo = 0, hi = min(i, n - 1 - i);
        int best = 0;
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            int l = i - mid, r = i + mid;
            int h1 = hs.substringHash(l, r);
            int h2 = hr.substringHash(n - 1 - r, n - 1 - l);
            
            if(h1 == h2) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        int len = 2 * best + 1;
        if(len > bestLen) {
            bestLen = len;
            bestStart = i - best;
        }
    }
    
    // Check even length palindromes centered between i and i + 1
    for(int i = 0; i < n - 1; i++) {
        int lo = 1, hi = min(i + 1, n - 1 - i);
        int best = 0;
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            int l = i - mid + 1, r = i + mid;
            int h1 = hs.substringHash(l, r);
            int h2 = hr.substringHash(n - 1 - r, n - 1 - l);
            
            if(h1 == h2) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        int len = 2 * best;
        if(len > bestLen) {
            bestLen = len;
            bestStart = i - best + 1;
        }
    }
    
    cout << s.substr(bestStart, bestLen) << "\n";
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