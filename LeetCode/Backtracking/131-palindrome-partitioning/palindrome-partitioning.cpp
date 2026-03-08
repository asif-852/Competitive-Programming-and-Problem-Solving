class Solution {
public:
    bool isPalindrome(const string& str, int start, int end) {
        for(int i = start, j = end; i <= j; i++, j--) {
            if(str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }
    void backtrack(int idx, const string& s, int n, vector<string>& curr, vector<vector<string>>& ans) {
        if(idx == n) {
            ans.push_back(curr);
            return;
        }
        for(int i = idx; i < n; i++) {
            if(isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, s, n, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        int n = s.size();
        backtrack(0, s, n, curr, ans);
        return ans;
    }
};