
#include <bits/stdc++.h>
using namespace std;
 
struct string_Hash {
    vector<int> primes = {10007, 12433, 10009, 12601, 10039, 12641, 10061, 12671, 34273,
                          12721, 10427, 13339, 35353, 13487, 67789, 13591, 68743, 13789,
                          72271, 28229, 76157, 29437, 80387, 30313, 81181, 30313, 84499,
                          13879, 86269, 25679, 89051, 26321, 90709, 26681, 98081, 27277};
    int P1, P2;
    vector<int> mods = {1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103,
        1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271,
        1000000289, 1000000297, 1000000321, 1000000349, 1000000363, 1000000403,
        1000000409, 1000000411, 1000000427, 1000000433, 1000000439, 1000000447,
        1000000453, 1000000459, 1000000483, 1000000513, 1000000531, 1000000579,
        1000000607, 1000000613, 1000000637, 1000000663, 1000000711, 1000000753};

    int mod1, mod2;
    int invp1, invp2, n;
    vector<int> pw1, pw2, invpw1, invpw2, pref1, pref2; // Using separate vectors for double hashing
    string s;

    string_Hash() {}
    string_Hash(string s, int idx1, int idx2) {
        init(s, idx1, idx2);
    }

    void init(string s, int idx1, int idx2) {
        this->s = s;
        n = s.size();
        P1 = primes[idx1];
        P2 = primes[idx2];
        mod1 = mods[idx1];
        mod2 = mods[idx2];
        pw1.resize(n);
        pw2.resize(n);
        invpw1.resize(n);
        invpw2.resize(n);
        pref1.resize(n);
        pref2.resize(n);
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
        pw1[0] = P1; pw2[0] = P2;

        for (int i = 1; i < n; i++) {
            pw1[i] = 1LL * pw1[i - 1] * P1 % mod1;
            pw2[i] = 1LL * pw2[i - 1] * P2 % mod2;
        }

        invp1 = binpower(P1, mod1 - 2, mod1);
        invp2 = binpower(P2, mod2 - 2, mod2);

        invpw1[0] = invp1; invpw2[0] = invp2;

        for (int i = 1; i < n; i++) {
            invpw1[i] = 1LL * invpw1[i - 1] * invp1 % mod1;
            invpw2[i] = 1LL * invpw2[i - 1] * invp2 % mod2;
        }
    }

    void build() {
        for (int i = 0; i < n; i++) {
            pref1[i] = 1LL * s[i] * pw1[i] % mod1;
            pref2[i] = 1LL * s[i] * pw2[i] % mod2;

            if (i) {
                pref1[i] = (pref1[i] + pref1[i - 1]) % mod1;
                pref2[i] = (pref2[i] + pref2[i - 1]) % mod2;
            }
        }
    }

    pair<int, int> substringHash(int i, int j) {
        assert(i <= j);

        int hs1 = pref1[j];
        if (i) {
            hs1 = (hs1 - pref1[i - 1] + mod1) % mod1;
        }
        hs1 = 1LL * hs1 * invpw1[i] % mod1;
        if(hs1 < 0) hs1 += mod1;

        int hs2 = pref2[j];
        if (i) {
            hs2 = (hs2 - pref2[i - 1] + mod2) % mod2;
        }
        hs2 = 1LL * hs2 * invpw2[i] % mod2;
        if(hs2 < 0) hs2 += mod2;

        return {hs1, hs2};
    }

    pair<int, int> fullStringHash() {
        return substringHash(0, n - 1);
    }
};

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

void solve() {
    string s;   
    cin >> s;
    int n = s.size();
    int idx1 = 0, idx2 = 0;
    while(idx1 == idx2) {
        idx1 = ((rand() % 36) + 36) % 36;
        idx2 = ((rand() % 36) + 36) % 36;
    }
    string_Hash H(s, idx1, idx2);
    vector<int> ans;
    for(int i = 0; i < n - 1; i++) {
        if(H.substringHash(0, i) == H.substringHash(n - 1 - i, n - 1)) {
            ans.push_back(i + 1);
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
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