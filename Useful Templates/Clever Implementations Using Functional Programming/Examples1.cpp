
// Conditional searches, counting elements, and finding elements in C++ STL

#include <bits/stdc++.h>
using namespace std;


void solve() {
    //std::any_of
    //This is a very useful function that returns true if any of the elements in the range [first, last) satisfies some condition. Let's say you want to figure out if an array contains at least one 9. You could just write the naive loop and waste time in contest.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        bool ok = 0;
        for(int i = 0; i < (int)(a).size(); i++) {
            if(a[i] == 9) {
                ok = 1;
                break;
            }
        }

        //but you could be smart and write this all in one line.
        ok = any_of(a.begin(), a.end(), [](int x) { return x == 9; });
        cout << (ok ? "YES" : "NO") << '\n';
    }
    




    //std::all_of
    //This is a very useful function that returns true if all of the elements in the range [first, last) satisfy some condition. Let's say you want to figure out if an array contains only even numbers.

    {
        vector<int> a = {2, 4, 6, 8, 10};
        bool ok = 1;
        for(int i = 0; i < (int)(a).size(); i++) {
            if(a[i] % 2 != 0) {
                ok = 0;
                break;
            }
        }

        ok = all_of(a.begin(), a.end(), [](int x) { return x % 2 == 0; });
        cout << (ok ? "YES" : "NO") << '\n';
    }





    //std::none_of
    //This is a very useful function that returns true if none of the elements in the range [first, last) satisfy some condition. Let's say you want to figure out if an array contains no 9s.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 10};
        bool ok = 1;
        for(int i = 0; i < (int)(a).size(); i++) {
            if(a[i] == 9) {
                ok = 0;
                break;
            }
        }

        ok = none_of(a.begin(), a.end(), [](int x) { return x == 9; });
        cout << (ok ? "YES" : "NO") << '\n';
    }




    //std:count
    //This is a very useful function that counts the number of elements in the range [first, last) that are equal to some value. Let's say you want to figure out how many 9s are in an array.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
        int cnt = 0;
        for(int i = 0; i < (int)(a).size(); i++) {
            if(a[i] == 9) {
                cnt++;
            }
        }

        cnt = count(a.begin(), a.end(), 9);
        cout << cnt << '\n';
    }




    //std::count_if
    //This is a very useful function that counts the number of elements in the range [first, last) that satisfy some condition. Let's say you want to figure out how many even numbers are in an array.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int cnt = 0;
        for(int i = 0; i < (int)(a).size(); i++) {
            if(a[i] % 2 == 0) {
                cnt++;
            }
        }

        cnt = count_if(a.begin(), a.end(), [](int x) { return x % 2 == 0; });
        cout << cnt << '\n';

        // another example: count the number of elements in an array that are greater than 5.
        int threshold = 5;
        cnt = count_if(a.begin(), a.end(), [threshold](int x) { return x > threshold; });
        cout << cnt << '\n';
    }
    
    
    
    
    //std::find
    //This is a very useful function that returns an iterator to the first element in the range [first, last) that is equal to some value. Let's say you want to figure out if an array contains a 9 and if it does, where the first 9 is.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int pos = -1;
        for(int i = 0; i < (int)(a).size(); i++) {
            if(a[i] == 9) {
                pos = i;
                break;
            }
        }

        auto it = find(a.begin(), a.end(), 9) - a.begin();
        cout << (it != (int)(a).size() ? "Found at index: " + to_string(it) : "Not found") << '\n';
    }




    //std::binary_search
    //This is a very useful function that returns true if the value exists in the sorted range [first, last). Let's say you want to figure out if an array contains a 9 and the array is sorted.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        bool ok = 0;
        //Manual binary search
        int l = 0, r = (int)(a).size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(a[mid] == 9) {
                ok = 1;
                break;
            } else if(a[mid] < 9) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ok = binary_search(a.begin(), a.end(), 9);
        cout << (ok ? "YES" : "NO") << '\n';
    }




    //std::max_element
    //This is a very useful function that returns an iterator to the maximum element in the range [first, last). Let's say you want to figure out the maximum element in an array.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int mx = a[0];
        for(int i = 1; i < (int)(a).size(); i++) {
            mx = max(mx, a[i]);
        }

        auto it = max_element(a.begin(), a.end());
        cout << "Maximum element: " << *it << '\n';
    }




    //std::min_element
    //This is a very useful function that returns an iterator to the minimum element in the range [first, last). Let's say you want to figure out the minimum element in an array.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int mn = a[0];
        for(int i = 1; i < (int)(a).size(); i++) {
            mn = min(mn, a[i]);
        }

        auto it = min_element(a.begin(), a.end());
        cout << "Minimum element: " << *it << '\n';
    }




    //std::is_sorted
    //This is a very useful function that returns true if the range [first, last) is sorted in non-decreasing order. Let's say you want to figure out if an array is sorted.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        bool ok = 1;
        for(int i = 1; i < (int)(a).size(); i++) {
            if(a[i] < a[i - 1]) {
                ok = 0;
                break;
            }
        }

        ok = is_sorted(a.begin(), a.end());
        cout << (ok ? "YES" : "NO") << '\n';
    }




    //std::accumulate
    //This is a very useful function that returns the sum of the elements in the range [first, last) plus an initial value. Let's say you want to figure out the sum of the elements in an array.

    {
        vector<int> a = {1, 2, 3, 4, 5};
        int sum = 0;
        for(int i = 0; i < (int)(a).size(); i++) {
            sum += a[i];
        }

        sum = accumulate(a.begin(), a.end(), 0);
        cout << "Sum: " << sum << '\n';
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
