class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char last_op = '+';
        int curr = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                curr = curr * 10 + (s[i] - '0');
            }
            if((!isdigit(s[i]) && !isspace(s[i])) || i == n - 1) {
                if(last_op == '+') {
                    st.push(curr);
                } else if(last_op == '-') {
                    st.push(-curr);
                } else if(last_op == '*') {
                    int top = st.top(); 
                    st.pop();
                    st.push(top * curr);
                } else if(last_op == '/') {
                    int top = st.top(); 
                    st.pop();
                    st.push(top / curr);
                }
                last_op = s[i];
                curr = 0;
            }
        }
        
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};