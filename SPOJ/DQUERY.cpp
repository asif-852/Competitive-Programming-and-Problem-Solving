
#include <bits/stdc++.h>
using namespace std;
 
int n, q;
int freq[1000001];
int distinct;
 
struct query{
    int L, R, q_no, block_no;
};
 
void Add(int ele) {
    distinct += (freq[ele] == 0);
    freq[ele]++;
}
 
void Remove(int ele) {
    distinct -= (freq[ele] == 1);
    freq[ele]--;
}
 
void adjust(int& curr_l, int& curr_r, query& qu, vector<int>& v) {
    while(curr_l < qu.L) Remove(v[curr_l++]);
    while(curr_l > qu.L) Add(v[--curr_l]);
    while(curr_r < qu.R) Add(v[++curr_r]);
    while(curr_r > qu.R) Remove(v[curr_r--]);
}
 
void MO(vector<query>& queries, vector<int>& v) {
    vector<int> answer(q);
    sort(queries.begin(), queries.end(), [&](const query& a, const query& b) {
        return (a.block_no == b.block_no) ? (a.R < b.R) : (a.block_no < b.block_no);
    });
    int curr_l = queries[0].L, curr_r = queries[0].R;
    for(int i = queries[0].L; i <= queries[0].R; i++) {
        Add(v[i]);
    }
    answer[queries[0].q_no] = distinct;
    for(int i = 1; i < q; i++) {
        adjust(curr_l, curr_r, queries[i], v);
        answer[queries[i].q_no] = distinct;
    }
    for(int i = 0; i < q; i++) {
        cout << answer[i] << '\n';
    }
}
 
void solve() {
 
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    cin >> q;
    vector<query> queries(q);
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i].L = l - 1;
        queries[i].R = r - 1;
        queries[i].q_no = i;
        queries[i].block_no = l / sqrt(n);
    }
    MO(queries, v);
 
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