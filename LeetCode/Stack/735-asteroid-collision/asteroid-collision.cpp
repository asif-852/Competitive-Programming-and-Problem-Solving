class Solution {
public:
    int explode(int x, int y) {
        if(abs(x) == abs(y)) {
            return 0;
        }
        return abs(x) > abs(y) ? x : y;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto val : asteroids) {
            bool pushed = 0;
            while(!st.empty() && st.top() > 0 && val < 0) {
                int val2 = st.top();
                st.pop();
                int winner = explode(val, val2);
                pushed = 1;
                if(winner == 0) {
                    break;
                }
                if(winner == val2) {
                    st.push(val2);
                    break;
                }
                if(winner == val) {
                    pushed = 0;
                }
            }
            if(!pushed) {
                st.push(val);
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};