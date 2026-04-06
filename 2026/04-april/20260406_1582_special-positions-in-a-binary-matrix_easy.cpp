/*
 * Problem 1582: Special Positions in a Binary Matrix
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
 *
 * Approach: Brute Force Row and Column Scan
 * For each cell containing a 1, scan its entire row and column to check if any other 1 exists.
 * If no other 1 is found in the same row or column, the position is considered special and counted.
 *
 * Time Complexity: O(n * m * (n + m))
 *   - For each of the n*m cells, we scan its row (m elements) and column (n elements).
 *
 * Space Complexity: O(1)
 *   - Only a constant number of auxiliary variables are used regardless of input size.
 *
 * Runtime: 4 ms
 * Memory: 16.5 MB
 */

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int val = 0;
        int found =0;
        int n = mat.size() , m = mat[0].size();
        for (int i=0; i<n ; i++) { 
            for (int j =0; j<m; j++) {
                if (mat[i][j] == 1) {
                    for (int k = 0; k < m; k++) {
                        if (k != j && mat[i][k] == 1) found = 1;
                    }
                    for (int k = 0; k < n; k++) {
                        if (k != i && mat[k][j] == 1) found = 1;
                    }
                    if (found==0) val+=1;
                }
                found =0;
            }
        }

        return val;
    }
};
