
// Modifying elements in STL containers 

#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    
    /*
     * std::partial_sum
     * This is a very useful function that computes the partial sums of the elements in the range [first, last) and stores the result in the range beginning at d_first.
     * Let's say you want to compute the prefix sums of an array.
     */
    {
        vector<int> a = {1, 2, 3, 4, 5};
        vector<int> prefix_sums((int)(a).size());   
        prefix_sums[0] = a[0];
        for(int i = 1; i < (int)(a).size(); i++) {
            prefix_sums[i] = prefix_sums[i - 1] + a[i];
        }

        a = {1, 2, 3, 4, 5};
        partial_sum(a.begin(), a.end(), prefix_sums.begin());   // Modified a: 1 3 6 10 15
        for(int x : prefix_sums) {
            cout << x << ' ';
        }
        cout << '\n';


        // another example: compute the suffix sums of an array.
        a = {1, 2, 3, 4, 5};
        vector<int> suffix_sums((int)(a).size());
        suffix_sums[(int)(a).size() - 1] = a[(int)(a).size() - 1];
        for(int i = (int)(a).size() - 2; i >= 0; i--) {
            suffix_sums[i] = suffix_sums[i + 1] + a[i];
        }

        a = {1, 2, 3, 4, 5};
        partial_sum(a.rbegin(), a.rend(), suffix_sums.rbegin());    // Modified a: 15 14 12 9 5
        for(int x : suffix_sums) {
            cout << x << ' ';
        }
        cout << '\n';
    }





    /*
     * std::adjacent_difference
     * This is a very useful function that computes the differences between adjacent elements in the range [first, last) and stores the result in the range beginning at d_first. 
     * Let's say you want to compute the differences between adjacent elements in an array.
     */
    {
        vector<int> a = {1, 3, 6, 10, 15};
        vector<int> differences((int)(a).size());
        differences[0] = a[0];
        for(int i = 1; i < (int)(a).size(); i++) {
            differences[i] = a[i] - a[i - 1];
        }

        a = {1, 3, 6, 10, 15};
        adjacent_difference(a.begin(), a.end(), differences.begin());   // Modified a: 1 2 3 4 5
        for(int x : differences) {
            cout << x << ' ';
        }
        cout << '\n';
    }





    /*
     * std::for_each
     * This is a very useful function that applies a function to each element in the range [first, last). 
     * Let's say you want to increment each element in an array.
     */
    {
        vector<int> a = {1, 2, 3, 4, 5};
        for(int i = 0; i < (int)(a).size(); i++) {
            a[i] += 1;   // modify each element in the array by adding 1 to it
        }

        a = {1, 2, 3, 4, 5};
        for_each(a.begin(), a.end(), [](int& x) { x += 1; });    // Modified a: 2 3 4 5 6
        for_each(a.begin(), a.end(), [](int x) { cout << x << ' '; });
        cout << '\n';
    }





    /*
     * std::transform
     * This is a very useful function that applies a function to each element in the range [first, last) and stores the result in the range beginning at d_first. 
     * Let's say you want to square each element in an array.
    */
    {
        vector<int> a = {1, 2, 3, 4, 5};
        vector<int> squared((int)(a).size());
        for(int i = 0; i < (int)(a).size(); i++) {
            squared[i] = a[i] * a[i];
        }

        a = {1, 2, 3, 4, 5};
        transform(a.begin(), a.end(), squared.begin(), [](int x) { return x * x; });    // squared: 1 4 9 16 25
        for(int x : squared) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    // Note: Transform is basically a more general version of for_each. It allows you to store the results of the function in a different container, whereas for_each modifies the elements in place.





    /*
    * std::iota
     * This is a very useful function that fills the range [first, last) with sequentially increasing values, starting from a given value.
     * Let's say you want to fill an array with the first n natural numbers.
    */
    {
        int n = 5;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = i + 1;
        }

        a = vector<int>(n);            // 0 0 0 0 0
        iota(a.begin(), a.end(), 1);   // Modified a: 1 2 3 4 5
        for(int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }




    // More useful cases of std::partial_sum

    // Suffix maximum of an array.

    {
        vector<int> a = {77, 128, 99, 42, 56};
        vector<int> suffix_max((int)(a).size());
        suffix_max.back() = a.back();
        for(int i = (int)(a).size() - 2; i >= 0; i--) {
            suffix_max[i] = max(a[i], suffix_max[i + 1]);
        }

        a = {77, 128, 99, 42, 56};
        partial_sum(a.rbegin(), a.rend(), suffix_max.rbegin(), [](int x, int y) { return max(x, y); });    // suffix_max: 128 128 99 56 56
        for(int x : suffix_max) {
            cout << x << ' ';
        }
        cout << '\n';
    }




    // Prefix xor of an array.

    {
        vector<int> a = {1, 2, 3, 4, 5};
        vector<int> prefix_xor((int)(a).size());
        prefix_xor[0] = a[0];
        for(int i = 1; i < (int)(a).size(); i++) {
            prefix_xor[i] = prefix_xor[i - 1] ^ a[i];
        }

        a = {1, 2, 3, 4, 5};
        partial_sum(a.begin(), a.end(), prefix_xor.begin(), [](int x, int y) { return x ^ y; });    // prefix_xor: 1 3 0 4 1
        for(int x : prefix_xor) {
            cout << x << ' ';
        }
        cout << '\n';
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

