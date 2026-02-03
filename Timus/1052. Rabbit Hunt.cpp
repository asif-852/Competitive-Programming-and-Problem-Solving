
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

void solve() {
    int n;
    cin >> n;
    vector<Point> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        unordered_map<string, int> slopecount;
        for(int j = 0; j < n; j++) {
            if(i != j) {
                int dx = v[j].x - v[i].x;
                int dy = v[j].y - v[i].y;
                int d = __gcd(dx, dy);
                dx /= d;
                dy /= d;
                string slope = to_string(dy) + "/" + to_string(dx);
                slopecount[slope]++;
            }
        }
        int currmax = 0;
        for(auto [slope, count] : slopecount) {
            currmax = max(currmax, count);
        }

        ans = max(ans, currmax + 1);
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
