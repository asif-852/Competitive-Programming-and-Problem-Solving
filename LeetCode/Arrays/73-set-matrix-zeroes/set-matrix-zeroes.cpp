// Approach 1: Space Complexity: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowBad = 0, firstColBad = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) {
                        firstRowBad = 1;
                    }
                    if(j == 0) {
                        firstColBad = 1;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstRowBad) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;    
            }
        }

        if(firstColBad) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;    
            }
        }
    }
};

// Approach 2: Space Complexity: O(m + n)

/*

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> badrows, badcolumns;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    badrows.push_back(i);
                    badcolumns.push_back(j);
                }
            }
        }
        for(int i : badrows) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
        for(int j : badcolumns) {
            for(int i = 0; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }
};

*/