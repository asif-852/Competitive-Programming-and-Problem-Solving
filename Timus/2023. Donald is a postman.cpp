
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    vector<string> v1 = {"Alice", "Ariel", "Aurora", "Phil", "Peter", "Olaf", "Phoebus", "Ralph", "Robin"};
    vector<string> v2 = {"Bambi", "Belle", "Bolt", "Mulan", "Mowgli", "Mickey", "Silver", "Simba", "Stitch"};
    vector<string> v3 = {"Dumbo", "Genie", "Jiminy", "Kuzko", "Kida", "Kenai", "Tarzan", "Tiana", "Winnie"};

    map<string, int> steps;

    for(auto u : v1) steps[u] = 0;
    for(auto u : v2) steps[u] = 1;
    for(auto u : v3) steps[u] = 2;

    int n;
    cin >> n;
    vector<string> v(n);
    for(auto &x : v) cin >> x;

    vector<int> ans;

    int curr = 0;
    for(auto u : v) {
        ans.push_back(abs(curr - steps[u]));
        curr = steps[u];
    }

    cout << accumulate(ans.begin(), ans.end(), 0) << '\n';
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