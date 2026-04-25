/*
 * Problem #118 - Pascal's Triangle (Easy)
 * LeetCode: https://leetcode.com/problems/pascals-triangle/
 *
 * Approach: Dynamic Programming (Bottom-Up)
 * Each row is initialized with all 1s, then inner elements are computed as the sum
 * of the two elements directly above them from the previous row (dp[i-1][j-1] + dp[i-1][j]).
 * The first and last elements of every row remain 1, handled by the default initialization.
 *
 * Time Complexity: O(n^2) - We iterate over each row and each element within the row,
 * resulting in a total of n*(n+1)/2 operations.
 *
 * Space Complexity: O(n^2) - The output triangle itself stores n*(n+1)/2 elements,
 * which constitutes the dominant space usage.
 *
 * Runtime: 0 ms | Memory: 9.6 MB
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        for(int i =0; i < numRows; i++) {
            vector<int> pos(i+1 , 1);
            for(int j = 1 ; j <i; j++ ) {
                pos[j]= dp[i-1][j-1] + dp[i-1][j]  ; 
            } 
            dp.push_back(pos);
        }
        return dp;
    }
};
