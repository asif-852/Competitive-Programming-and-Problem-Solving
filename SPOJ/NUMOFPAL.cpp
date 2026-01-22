
// Approach 1: Expand Around Center (O(n^2) time complexity)
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    string s;
    cin >> s;
    long long ans = 0;
    int n = s.size();
    
    // Odd length palindromes
    for(int mid = 0; mid < n; mid++) {
        for(int x = 0; mid - x >= 0 && mid + x < n; x++) {
            if(s[mid - x] != s[mid + x]) {
                break;
            }
            ans++;
        }
    }
 
    // Even length palindromes
    for(int mid = 0; mid < n; mid++) {
        for(int x = 0; mid - x + 1 >= 0 && mid + x < n; x++) {
            if(s[mid - x + 1] != s[mid + x]) {
                break;
            }
            int len = 2 * x;
            if(s.substr(mid - x + 1, len) == "") {
                continue;
            }
            ans++;
        }
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


// Approach 2: Manacher's Algorithm (O(n) time complexity)

/*

#include <bits/stdc++.h>
using namespace std;
 
 
void solve() {
 
    string s;
    cin >> s;
    string t = "$";
    for(auto u : s) {
        t += u;
        t += '$';
    }
    int n = t.size();
    vector<int> p(n);
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(p[l + r - i], r - i + 1);   
        while(i - k >= 0 && i + k < n && t[i - k] == t[i + k]) k++;
        p[i] = k--;
        if(i + k > r) {
            r = i + k;
            l = i - k;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (t[i] == '$') ? (p[i] - 1) / 2 : p[i] / 2;
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

*/