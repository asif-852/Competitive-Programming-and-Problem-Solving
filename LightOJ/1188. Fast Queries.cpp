
#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> freq;
int uniques;

struct query {
    int L, R, q_no, block_no;
};

void Add(int x) {
    freq[x]++;
    if(freq[x] == 1) uniques++;
}

void Remove(int x) {
    if(freq[x] == 1) uniques--;
    freq[x]--;
}

void adjust(int& curr_l, int& curr_r, query& qu, vector<int>& v) {
    while(curr_l < qu.L) Remove(v[curr_l++]);
    while(curr_l > qu.L) Add(v[--curr_l]);
    while(curr_r < qu.R) Add(v[++curr_r]);
    while(curr_r > qu.R) Remove(v[curr_r--]);
}

void MO(vector<query>& queries, vector<int>& v) {
    vector<long long> answer(q);
    sort(queries.begin(), queries.end(), [&](const query& a, const query& b) {
        return (a.block_no == b.block_no) ? (a.R < b.R) : (a.block_no < b.block_no);
    });

    int curr_l = queries[0].L, curr_r = queries[0].R;
    for(int i = curr_l; i <= curr_r; i++) {
        Add(v[i]);
    }
    answer[queries[0].q_no] = uniques;

    for(int i = 1; i < q; i++) {
        adjust(curr_l, curr_r, queries[i], v);
        answer[queries[i].q_no] = uniques;
    }
    for(int i = 0; i < q; i++) {
        cout << answer[i] << '\n';
    }
}


void solve() {
    cin >> n >> q;
    vector<int> v(n);
    for(auto& x : v) cin >> x;

    freq.resize(*max_element(v.begin(), v.end()) + 1);
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
    cin >> t;
    for(int i = 1; i <= t; i++) {
        freq.clear();
        uniques = 0;
        cout << "Case " << i << ":\n";
        solve();
    }

    return 0;
}

