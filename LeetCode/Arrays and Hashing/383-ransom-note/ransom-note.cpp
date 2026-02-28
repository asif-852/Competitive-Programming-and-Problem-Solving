class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26);
        for(auto u : ransomNote) {
            cnt[u - 'a']++;
        }
        for(auto u : magazine) {
            if(cnt[u - 'a']) {
                cnt[u - 'a']--;
            }
        }
        return count(cnt.begin(), cnt.end(), 0) == 26;
    }
};