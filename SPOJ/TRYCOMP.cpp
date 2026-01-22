
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
const int N = 5e6;
int nxt[N][26];
vector<int> best(N, 1e7);
int total = 1;
gp_hash_table<string, int> freq;

// Adds string s with index idx to the trie
void add_string(string s, int idx) {
    int curr = 1;
    best[curr] = min(best[curr], idx);
    for(int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
        if(!nxt[curr][ch]) {
            nxt[curr][ch] = ++total;
        }
        curr = nxt[curr][ch];
        best[curr] = min(best[curr], idx);
    }
}

// Queries the trie for string t and returns the index of the best matching string
int query(string t) {
    int curr = 1;
    for(int i = 0; i < t.size(); i++) {
        int ch = t[i] - 'a';
        if(!nxt[curr][ch]) {
            return -1;
        }
        curr = nxt[curr][ch];
    }
    return best[curr];
}

void solve() { 
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v[i] = s;
        freq[s]++;
    }
    sort(v.begin(), v.end(), [&](const string& l, const string& r) {
        return (freq[l] == freq[r]) ? (l < r) : (freq[l] > freq[r]);
    });
 
    for(int i = 0; i < n; i++) {
        add_string(v[i], i);
    }
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        int idx = query(s);
        if(idx == -1) {
            cout << -1 << '\n';
            continue;
        }
        cout << v[idx] << " " << freq[v[idx]] << '\n';
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