class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                int width = (st.empty() ? i : i - st.top() - 1);
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }
};