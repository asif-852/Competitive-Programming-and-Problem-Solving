class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        // unordered_map<char, int> cnt1, cnt2;
        // vector<int> cnt1(52), cnt2(52); // also works but want to avoid cnt[c - 'a'] kind of thing here for better readability.
        vector<int> cnt1(128), cnt2(128);
        int formed = 0, required = 0;
        for(auto u : t) {
            if(cnt2[u] == 0) {
                required++;
            }
            cnt2[u]++;
        }
        int len = 1e9, l = 0, ans_l = -1;
        for(int r = 0; r < m; r++) {
            char c = s[r];
            cnt1[c]++;
            if(cnt2[c] && cnt1[c] == cnt2[c]) {
                formed++;
            }
            while(formed == required) {
                if((r - l + 1) <= len) {
                    len = r - l + 1;
                    ans_l = l;
                }
                char left_c = s[l];
                if(cnt2[left_c] && cnt1[left_c] == cnt2[left_c]) {
                    formed--;
                }
                cnt1[left_c]--;
                l++;
            } 
            
        }
        if(ans_l == -1) {
            return "";
        }
        return s.substr(ans_l, len);
    }
};