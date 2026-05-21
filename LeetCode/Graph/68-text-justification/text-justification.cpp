class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int currlen = 0, currwords = 0;
        vector<string> ans;
        vector<int> groups;
        for(auto u : words) {
            if(currlen + currwords + u.size() > maxWidth) {
                currlen = u.size();
                groups.push_back(currwords);
                currwords = 1;
                continue;
            }
            currlen += u.size();
            currwords++;
        }
        groups.push_back(currwords);

        int i = 0;
        for(int it = 0; it < groups.size(); it++) {
            int u = groups[it];
            vector<string> currstrings;
            int total_length = 0;
            for(int k = 0; k < u; k++) {
                total_length += words[i].size();
                currstrings.push_back(words[i++]);
            }
            int spaces = maxWidth - total_length;
            if(u == 1) {
                ans.push_back(currstrings[0] + string(spaces, ' '));
                continue;
            }
            vector<int> splits(u - 1);
            int rem = spaces % (u - 1);
            for(int i = 0; i < (u - 1); i++) {
                splits[i] = spaces / (u - 1) + 1 * (rem-- > 0);
            }
            if(it == groups.size() - 1) {
                splits = vector<int> (u - 1, 1);
            }
            string currans;
            for(int i = 0; i < (u - 1); i++) {
                currans += currstrings[i];
                currans += string(splits[i], ' ');
            }
            currans += currstrings.back();
            if(it == groups.size() - 1) {
                currans += string(maxWidth - (total_length + u - 1), ' ');
            }
            ans.push_back(currans);
        }

        return ans;
    }
};