class Solution {
public:
    int calculate(string s) {
        stack<int> st; 
        int result = 0;
        int sign = 1;  // 1 for positive, -1 for negative
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                // Parsing number (multi-digit)
                long long num = 0;
                while(i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                i--;
                result += sign * num;
            } else if(s[i] == '+') {
                sign = 1;
            } else if(s[i] == '-') {
                sign = -1;
            } else if(s[i] == '(') {
                // Push current result and sign onto stack for later
                st.push(result);
                st.push(sign);
                // Reset result and sign for the new sub-expression
                result = 0;
                sign = 1;
            } else if(s[i] == ')') {
                int prev_sign = st.top(); 
                st.pop();
                int prev_result = st.top(); 
                st.pop();
                result = prev_result + (prev_sign * result);
            }
        }
        
        return result;
    }
};