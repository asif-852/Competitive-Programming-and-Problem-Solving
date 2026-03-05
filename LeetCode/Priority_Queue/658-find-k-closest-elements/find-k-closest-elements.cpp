// Approach 1: Binary Search + Two pointers, Time Complexity: O(log(n - k) + k), Space Complexity: O(1)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(); 
        int r = lower_bound(arr.begin(), arr.end() - k, x) - arr.begin(); 
        int l = r - 1;
        while(k--) {
            (l >= 0 && x - arr[l] <= arr[r] - x) ? l-- : r++;
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};


// Approach 2: Priority Queue, Time Complexity: O(n + klogk), Space Complexity: O(k)

/*

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        for(auto& u : arr) {
            pq.push({abs(u - x), u});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            auto [_, val] = pq.top();
            pq.pop();
            ans.push_back(val);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

*/