
#include <bits/stdc++.h>
using namespace std;

const int N = 9e5;
vector<vector<int>> nxt;
vector<int> cnt, len;
int total = 1;

int change(int n) {
    if(n + 'A' == 'A') return 0;
    if(n + 'A' == 'C') return 1;
    if(n + 'A' == 'G') return 2;
    if(n + 'A' == 'T') return 3;
}

void add_string(string s) {
    int curr = 1;
    cnt[curr]++;
    for(int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'A';
        ch = change(ch);
        if(!nxt[curr][ch]) {
            nxt[curr][ch] = ++total;
        }
        len[nxt[curr][ch]] = len[curr] + 1;
        curr = nxt[curr][ch];
        cnt[curr]++;
    }
}

void solve() {
    nxt.resize(N, vector<int>(4));
    cnt.resize(N);
    len.resize(N);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add_string(s);
    }
    int ans = -1;
    for(int i = 2; i < N; i++) {
        ans = max(ans, len[i] * cnt[i]);
    }
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        nxt.clear();
        cnt.clear();
        len.clear();
        total = 1;
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}