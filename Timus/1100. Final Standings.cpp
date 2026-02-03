
#include <bits/stdc++.h>
using namespace std;
 
struct Team {
    long long id, score, index;
};

void solve() {
    int n;
    cin >> n;
    vector<Team> teams(n);
    for(int i = 0; i < n; i++) {
        cin >> teams[i].id >> teams[i].score;
        teams[i].index = i;
    }
    sort(teams.begin(), teams.end(), [] (const Team& t1, const Team& t2) {
        return (t1.score == t2.score) ? (t1.index < t2.index) : (t1.score > t2.score);
    });
    for(auto t : teams) {
        cout << t.id << " " << t.score << '\n';
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