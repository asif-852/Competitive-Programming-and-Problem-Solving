
#include <bits/stdc++.h>
using namespace std;
 
class SegTree {
    struct Node{
        int zero = 0, one = 0, two = 0;
    };
    vector<Node> segTree;
    vector<long long> lazy;
public:
    void buildTree(int &n, vector<int> a) {
        segTree.resize(4 * n);
        lazy.resize(4 * n, 0);
        buildTree(a, 0, n - 1, 1);
    }
 
    void buildTree(const vector<int> &a, int left, int right, int node) {
        if (left == right) {
            segTree[node].zero = (a[left] % 3 == 0);
        } else {
            int mid = (left + right) / 2;
            buildTree(a, left, mid, 2 * node);
            buildTree(a, mid + 1, right, 2 * node + 1);
            segTree[node].zero = segTree[2 * node].zero + segTree[2 * node + 1].zero;
        }
    }
 
    long long rangeQuery(int node, int left, int right, int l, int r) {
        if (lazy[node]) {
            lazy[node] %= 3;
            for(int i = 1; i <= lazy[node]; i++) {
                swap(segTree[node].zero, segTree[node].two);
                swap(segTree[node].one, segTree[node].two);
            }
            if (left != right) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (left >= l && right <= r) {
            return segTree[node].zero;
        } else if (right < l || left > r) {
            return 0;
        } else {
            int mid = (left + right) / 2;
            return rangeQuery(2 * node, left, mid, l, r) + rangeQuery(2 * node + 1, mid + 1, right, l, r);
        }
    }
 
 
    void rangeUpdate(int node, int left, int right, int l, int r, int newVal) {
        if (lazy[node]) {
            lazy[node] %= 3;
            for(int i = 1; i <= lazy[node]; i++) {
                swap(segTree[node].zero, segTree[node].two);
                swap(segTree[node].one, segTree[node].two);
            }
            if (left != right) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (left >= l && right <= r) {
            swap(segTree[node].zero, segTree[node].two);
            swap(segTree[node].one, segTree[node].two);
            if (left != right) {
                lazy[2 * node] += newVal;
                lazy[2 * node + 1] += newVal;
            }
        } else if (right < l || left > r) {
            return;
        } else {
            int mid = (left + right) / 2;
            rangeUpdate(2 * node, left, mid, l, r, newVal);
            rangeUpdate(2 * node + 1, mid + 1, right, l, r, newVal);
            segTree[node].zero = segTree[2 * node].zero + segTree[2 * node + 1].zero;
            segTree[node].one = segTree[2 * node].one + segTree[2 * node + 1].one;
            segTree[node].two = segTree[2 * node].two + segTree[2 * node + 1].two;
        }
    }
};
 
 
void solve() {
 
    int n, q;
    cin >> n >> q;
    SegTree Tree;
    vector<int> values(n, 0);
    Tree.buildTree(n, values);
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r;
            cin >> l >> r;
            cout << Tree.rangeQuery(1, 1, n, l + 1, r + 1) << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            Tree.rangeUpdate(1, 1, n, l + 1, r + 1, 1);
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
 
    return 0;
} 