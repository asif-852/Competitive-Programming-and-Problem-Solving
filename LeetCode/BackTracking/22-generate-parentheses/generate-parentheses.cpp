class Solution {
public:
    void backtrack(int n, int open_count, int close_count, string& current_string, vector<string>& result) {
        if(current_string.length() == 2 * n) {
            result.push_back(current_string);
            return;
        }

        if(open_count < n) {
            current_string.push_back('(');                                      
            backtrack(n, open_count + 1, close_count, current_string, result);  
            current_string.pop_back();                                          
        }
        if(close_count < open_count) {
            current_string.push_back(')');
            backtrack(n, open_count, close_count + 1, current_string, result);
            current_string.pop_back();                                  
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current_string = "";
        backtrack(n, 0, 0, current_string, result);
        return result;
    }
};

// Approach 2: BFS

/*

class Solution {
public:
    struct State {
        string current_string;
        int open_count;
        int close_count;
    };
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        queue<State> q;
        q.push({"", 0, 0});

        while(!q.empty()) {
            State curr = q.front();
            q.pop();

            if(curr.current_string.length() == 2 * n) {
                result.push_back(curr.current_string);
                continue; 
            }

            if(curr.open_count < n) {
                q.push({curr.current_string + "(", curr.open_count + 1, curr.close_count});
            }

            if(curr.close_count < curr.open_count) {
                q.push({curr.current_string + ")", curr.open_count, curr.close_count + 1});
            }
        }
        
        return result;
    }
};

*/