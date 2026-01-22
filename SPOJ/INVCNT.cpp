
// Approach 1: Using Ordered Set from PBDS to count inversions

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 

void solve() {
    int n;
    cin >> n;
    ordered_set s;
    long long ans = 0;
    while(n--) {
        int x;
        cin >> x;
        ans += s.order_of_key(x);
        s.insert(x);
    }
    cout << ans << '\n';
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


// Approach 2: Using Merge Sort to count inversions

/*

#include <bits/stdc++.h>
using namespace std;
 
long long merge_sort(vector<int>& A, int p, int r) {
    if(p >= r) return 0;
 
    int q = (p + r) / 2;
    long long inversions = merge_sort(A, p, q) + merge_sort(A, q + 1, r);
 
    int i = p;
    int j = q + 1;
    vector<int> B;
    while(i <= q && j <= r) {
        if(A[i] > A[j]) {
            inversions += q - i + 1;
            B.push_back(A[j]);
            j++;
        } else {
            B.push_back(A[i]);
            i++;
        }
    }
 
    while(i <= q) {
        B.push_back(A[i]);
        i++;
    }
    while(j <= r) {
        B.push_back(A[j]);
        j++;
    }
    for(int k = p; k <= r; k++) {
        A[k] = B[k - p];
    }
 
    return inversions;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    cout << merge_sort(v, 0, n - 1) << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
 
    return 0;
} 

*/