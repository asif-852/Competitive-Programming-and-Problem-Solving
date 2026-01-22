
// Approach: Sqrt Decomposition

#include <bits/stdc++.h>
using namespace std;
 
void Update(int id, int val, vector<int>& arr, vector<vector<int>>& block, int len) {
    int b = id / len;
    int idx = lower_bound(block[b].begin(), block[b].end(), arr[id]) - block[b].begin();
    block[b][idx] = arr[id] = val;
    sort(block[b].begin(), block[b].end());
}
 
int Query(int l, int r, int x, const vector<int>& arr, const vector<vector<int>>& block, int len) {
    int ans = 0;
    int L = l / len, R = r / len;
    if(L == R) {
        for(int i = l; i <= r; i++) {
            ans += (arr[i] <= x);
        }
    }
    else {
        for(int i = L * len + len - 1; i >= l; i--) {
            ans += (arr[i] <= x);
        }
        for(int i = L + 1; i < R; i++) {
            ans += upper_bound(block[i].begin(), block[i].end(), x) - block[i].begin();
        }
        for(int i = R * len; i <= r; i++) {
            ans += (arr[i] <= x);
        }
    }
    return ans;
}
 
void solve() {
 
    int n, q;
    cin >> n >> q;
    int len = sqrt(n) + 1;
 
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    vector<vector<int>> block(len, vector<int>());
    for(int i = 0; i < n; i++) {
        block[i / len].push_back(arr[i]);
    }
 
    for(int i = 0; i < len; i++) {
        sort(block[i].begin(), block[i].end());
    }
 
    while (q--) {
        char typ;
        cin >> typ;
        if(typ == 'C') {
            int l, r, x;
            cin >> l >> r >> x;
            cout << Query(l - 1, r - 1, x, arr, block, len) << '\n';
        }
        else {
            int l, v;
            cin >> l >> v;
            Update(l - 1, v, arr, block, len);
        }
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
}