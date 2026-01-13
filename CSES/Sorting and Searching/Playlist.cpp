
// Approach 1: Sliding Window
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    int ans = -1;
    map<int, int> cnt;
    for(int i = 0, j = 0; j < n; j++) {
        cnt[v[j]]++;
        while(cnt[v[j]] > 1) {
            cnt[v[i++]]--;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans << '\n';
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


// Approach 2: Binary Search + Co-ordinate Compression

/*

#include <bits/stdc++.h>
using namespace std;

int freq[200001];
 
bool ok(vector<int> v, int mid) {
    memset(freq, 0, sizeof(freq));
    bool f = 0;
    int cnt = 0;
    for(int i = 0; i < mid; i++) {
        freq[v[i]]++;
        if(freq[v[i]] == 1) cnt++;
    }
    f |= (cnt == mid);
    for(int i = mid; i < v.size(); i++) {
        freq[v[i - mid]]--;
        if(freq[v[i - mid]] == 0) cnt--;
        freq[v[i]]++;
        if(freq[v[i]] == 1) cnt++;
        f |= (cnt == mid);
    }
    return f;
}
 
void solve() {

    int n;
    cin >> n;
    set<int> st;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        st.insert(v[i]);
    }
    map<int, int> mp;
    int id = 0;
    for(auto u : st) mp[u] = id++;
    for(int i = 0; i < n; i++) {
        v[i] = mp[v[i]];
    }
    //debug(v);
 
    int l = 1, r = n, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        ok(v, mid) ? l = mid + 1, ans = mid : r = mid - 1;
    }
    cout << ans << '\n';
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


*/



