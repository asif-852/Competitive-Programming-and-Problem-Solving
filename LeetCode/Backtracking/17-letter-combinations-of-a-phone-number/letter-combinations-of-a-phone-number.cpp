class Solution {
public:
    void backtrack(const string& digits, int index, const vector<string>& letters, 
                   string& current_combination, vector<string>& result) {
        if(index == digits.size()) {
            result.push_back(current_combination);
            return;
        }

        int current_digit = digits[index] - '0'; 
        for(auto letter : letters[current_digit]) {
            current_combination.push_back(letter);
            backtrack(digits, index + 1, letters, current_combination, result);
            current_combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return {};
        }
        vector<string> letters = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        string current_combination = "";
        backtrack(digits, 0, letters, current_combination, result);
        return result;
    }
};