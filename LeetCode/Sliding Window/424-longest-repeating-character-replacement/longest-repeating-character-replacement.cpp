class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int ans = 0, l = 0, maxFreq = 0;

        for(int r = 0; r < s.size(); r++) {
            freqs[s[r]]++;
            maxFreq = max(maxFreq, freqs[s[r]]);
            while((r - l + 1) - maxFreq > k) {
                freqs[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
