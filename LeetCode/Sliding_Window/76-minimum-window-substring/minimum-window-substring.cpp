class Solution {
public:
    bool enough(unordered_map<char, int>& cnt1, unordered_map<char, int>& cnt2) {
        bool ok = 1;
        for(auto [c, freq] : cnt2) {
            ok &= (cnt1[c] >= freq);
        }
        return ok;
    }

    string minWindow(string s, string t) {
        int m = s.size();
        unordered_map<char, int> cnt1, cnt2;
        for(auto u : t) {
            cnt2[u]++;
        }
        int len = 1e9, l = 0, ans_l = -1;
        for(int r = 0; r < m; r++) {
            cnt1[s[r]]++;
            while(enough(cnt1, cnt2)) {
                if((r - l + 1) <= len) {
                    len = r - l + 1;
                    ans_l = l;
                }
                cnt1[s[l]]--;
                l++;
            } 
            
        }
        if(ans_l == -1) {
            return "";
        }
        return s.substr(ans_l, len);
    }
};