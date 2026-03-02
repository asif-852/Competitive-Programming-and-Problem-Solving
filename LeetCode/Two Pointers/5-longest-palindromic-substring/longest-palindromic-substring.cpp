class Solution {
public:
    string longestPalindrome(string s) {
        int best = 1;
        string ans;
        int n = s.size();

        for(int mid = 0; mid < n; mid++) {
            for(int x = 0; mid - x >= 0 && mid + x < n; x++) {
                if(s[mid - x] != s[mid + x]) {
                    break;
                }
                int len = 2 * x + 1;
                if(len >= best) {
                    best = len;
                    ans = s.substr(mid - x, len);
                }
            }
        }

        for(int mid = 0; mid < n; mid++) {
            for(int x = 1; mid - x + 1 >= 0 && mid + x < n; x++) {
                if(s[mid - x + 1] != s[mid + x]) {
                    break;
                }
                int len = 2 * x;
                if(len >= best) {
                    best = len;
                    ans = s.substr(mid - x + 1, len);
                }
            }
        }

        return ans;
    }
};