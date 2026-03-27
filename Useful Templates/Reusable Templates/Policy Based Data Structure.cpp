
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,    // Change to greater<T> for descending order
    rb_tree_tag,
    tree_order_statistics_node_update
>;

gp_hash_table<int, int> hash_table; // Example of a hash table using GNU PBDS

void solve() {
    // Example usage of ordered_set
    ordered_set<int> s;
    s.insert(3);
    s.insert(5);
    s.insert(8);
    s.insert(1);

    
    cout << *s.find_by_order(0) << '\n'; // Output: 1 (smallest element)
    cout << *s.find_by_order(1) << '\n'; // Output: 3 (second smallest element)
    cout << *s.find_by_order(2) << '\n'; // Output: 5 (third smallest element)
    cout << *s.find_by_order(3) << '\n'; // Output: 8 (fourth smallest element)
    
    cout << s.order_of_key(4) << '\n'; // Output: 2 (number of elements less than 4)
    cout << s.order_of_key(5) << '\n'; // Output: 2 (number of elements less than 5)
    cout << s.order_of_key(6) << '\n'; // Output: 3 (number of elements less than 6)


    // Example usage of hash_table
    hash_table[1] = 10;
    cout << hash_table[1] << '\n'; // Output: 10
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