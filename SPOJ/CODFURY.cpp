
#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    partial_sum(a.begin(), a.end(), a.begin());
    vector<pair<long long, long long>> answers;
    for(long long j = 0, i = 1; i <= n;) {
        if( (a[i] - a[j] <= k) ) {
            answers.push_back({a[i] - a[j], i - j});
            i++;
        }
        else j++;
    }
    sort(answers.begin(), answers.end(), [&](const pair<long long, long long>& x, const pair<long long, long long>& y) {
        return (x.second == y.second) ? (x.first < y.first) : (x.second > y.second);
    });
    cout << answers[0].first << " " << answers[0].second << '\n';
 
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