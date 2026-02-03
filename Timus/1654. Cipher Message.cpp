
#include <bits/stdc++.h>
using namespace std;
 

void solve() {
    string s;
    cin >> s;
    stack<char> st;
    string result = "";
    for(char c : s) {
        if(!st.empty() && c == st.top()) st.pop();
        else st.push(c);
    }

    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    cout << result << '\n';
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