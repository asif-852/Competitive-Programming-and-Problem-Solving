class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;
        for(auto u : tokens) {
            if(u == "+" || u == "-" || u == "*" || u == "/") {
                int num2 = ans.top();
                ans.pop();
                int num1 = ans.top();
                ans.pop();
                if(u == "+") {
                    ans.push(num1 + num2);
                } else if(u == "-") {
                    ans.push(num1 - num2);
                } else if(u == "*") {
                    ans.push(num1 * num2);
                } else if(u == "/") {
                    ans.push(num1 / num2);
                }
            } else {
                ans.push(stoi(u));
            }
        }
        return ans.top();
    }
};