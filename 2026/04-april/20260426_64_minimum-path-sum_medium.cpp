/*
 * Problem #64 - Minimum Path Sum (Medium)
 * LeetCode: https://leetcode.com/problems/minimum-path-sum/
 *
 * Approach: Bottom-Up Dynamic Programming
 * Build a DP table where dp[i][j] represents the minimum path sum to reach cell (i, j).
 * Initialize the first row and column with cumulative sums (only one direction to travel),
 * then fill remaining cells by taking the minimum of coming from the left or from above,
 * adding the current cell's value to propagate the optimal cost.
 *
 * Time Complexity: O(m * n) — every cell in the grid is visited exactly once.
 * Space Complexity: O(m * n) — a full DP table of the same dimensions as the input grid is used.
 *
 * Runtime: 5 ms
 * Memory: 16.3 MB
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for(int i=1; i<m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0] ;
        }
        for(int j=1; j<n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i = 1 ; i<m; i++){
            for(int j=1; j< n; j++) {
                dp[i][j] = min(dp[i][j-1] + grid[i][j] , dp[i-1][j]+ grid[i][j]);
            }
        }
        return dp[m-1][n-1];
    }
};
