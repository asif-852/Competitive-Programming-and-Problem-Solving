class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> group;
        for(auto u : strs) {
            string temp = u;
            sort(temp.begin(), temp.end());
            group[temp].push_back(u);
        }
        vector<vector<string>> ans;
        for(auto u : group) {
            ans.push_back(u.second);
        }
        return ans;
    }
};