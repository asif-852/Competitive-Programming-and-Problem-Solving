// Approach 1: Time Complexity: O(n), Space Complexity: O(k)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++) {
            // Ensuring outdated elements are out of the window
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // Ensuring decreasing order
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

// Approach 2: Time Complexity: O(nlogk), Space Complexity: O(k)

/*

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> st;
        for(int i = 0; i < nums.size(); i++) {
            if(i >= k) {
                st.erase(st.find(nums[i - k]));
            }
            st.insert(nums[i]);
            if(i >= k - 1) {
                ans.push_back(*st.rbegin());
            }
        }
        return ans;
    }
};

*/