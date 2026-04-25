/*
 * Problem #119 - Pascal's Triangle II (Easy)
 * https://leetcode.com/problems/pascals-triangle-ii/
 *
 * Approach: Dynamic Programming (Full Triangle Generation)
 * Builds the entire Pascal's Triangle up to the requested row using a 2D DP array.
 * Each cell is computed as the sum of the two cells directly above it from the previous row,
 * with boundary cells initialized to 1. The target row is then returned by index.
 *
 * Time Complexity: O(rowIndex^2) - generates all rows from 0 to rowIndex,
 * with each row i requiring O(i) work to fill its inner elements.
 *
 * Space Complexity: O(rowIndex^2) - stores all rows of the triangle up to rowIndex
 * in a 2D vector before returning the desired row.
 *
 * Runtime: 0 ms | Memory: 9.1 MB
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        for(int i =0; i <= numRows; i++) {
            vector<int> pos(i+1 , 1);
            for(int j = 1 ; j <i; j++ ) {
                pos[j]= dp[i-1][j-1] + dp[i-1][j]  ; 
            } 
            dp.push_back(pos);
        }
        return dp;
    }
    vector<int> getRow(int rowIndex) {
        return generate(rowIndex)[rowIndex];
    }
};

