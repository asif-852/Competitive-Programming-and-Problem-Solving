#include <bits/stdc++.h>
using namespace std;


void solve() {
    //std::any_of
    //This is a very useful function that returns true if any of the elements in the range [first, last) satisfies some condition. Let's say you want to figure out if an array contains at least one 9. You could just write the naive loop and waste time in contest.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        bool ok = 0;
        for(int i = 0; i < (int)(a).size(); ++i) {
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
    //This is a very useful function that returns true if all of the elements in the range [first, last) satisfy some condition. Let's say you want to figure out if an array contains only even numbers. You could just write the naive loop and waste time in contest.

    {
        vector<int> a = {2, 4, 6, 8, 10};
        bool ok = 1;
        for(int i = 0; i < (int)(a).size(); ++i) {
            if(a[i] % 2 != 0) {
                ok = 0;
                break;
            }
        }

        ok = all_of(a.begin(), a.end(), [](int x) { return x % 2 == 0; });
        cout << (ok ? "YES" : "NO") << '\n';
    }





    //std::none_of
    //This is a very useful function that returns true if none of the elements in the range [first, last) satisfy some condition. Let's say you want to figure out if an array contains no 9s. You could just write the naive loop and waste time in contest.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 10};
        bool ok = 1;
        for(int i = 0; i < (int)(a).size(); ++i) {
            if(a[i] == 9) {
                ok = 0;
                break;
            }
        }

        ok = none_of(a.begin(), a.end(), [](int x) { return x == 9; });
        cout << (ok ? "YES" : "NO") << '\n';
    }




    //std:count
    //This is a very useful function that counts the number of elements in the range [first, last) that are equal to some value. Let's say you want to figure out how many 9s are in an array. You could just write the naive loop and waste time in contest.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
        int cnt = 0;
        for(int i = 0; i < (int)(a).size(); ++i) {
            if(a[i] == 9) {
                cnt++;
            }
        }

        cnt = count(a.begin(), a.end(), 9);
        cout << cnt << '\n';
    }




    //std::count_if
    //This is a very useful function that counts the number of elements in the range [first, last) that satisfy some condition. Let's say you want to figure out how many even numbers are in an array. You could just write the naive loop and waste time in contest.

    {
        vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int cnt = 0;
        for(int i = 0; i < (int)(a).size(); ++i) {
            if(a[i] % 2 == 0) {
                cnt++;
            }
        }

        cnt = count_if(a.begin(), a.end(), [](int x) { return x % 2 == 0; });
        cout << cnt << '\n';
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
