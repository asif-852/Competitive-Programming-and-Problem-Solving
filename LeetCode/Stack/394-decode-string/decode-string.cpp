class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        stack<int> mul;
        for(int i = 0; i < s.size(); i++) {
            char u = s[i];
            if(u <= '9' && u >= '0') {
                string num;
                while(s[i] <= '9' && s[i] >= '0') {
                    num += s[i++];
                }
                mul.push(stoi(num));
                i--;
                continue;
            } 
            if(u == ']') {
                string temp;
                while(st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(), temp.end());
                int k = mul.top();
                mul.pop();
                string add;
                for(int j = 0; j < k; j++) {
                    add += temp;
                }
                for(auto v : add) {
                    st.push(v);
                }
            } else {
                st.push(u);
            }
        }
        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};