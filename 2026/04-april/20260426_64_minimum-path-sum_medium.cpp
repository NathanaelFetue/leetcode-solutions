/*
 * Problem #64 - Minimum Path Sum (Medium)
 * https://leetcode.com/problems/minimum-path-sum/
 *
 * Approach: Space-Optimized Dynamic Programming
 * Use a 1D DP array of size n to represent the minimum path sum to reach each cell in the current row.
 * Initialize the first row with cumulative sums, then for each subsequent row update dp[0] by accumulating
 * the left column values, and for each other cell take the minimum of the cell above (dp[j]) or the cell
 * to the left (dp[j-1]), adding the current grid value.
 *
 * Time Complexity : O(m * n) - every cell in the grid is visited exactly once
 * Space Complexity: O(n) - only a single row DP array is maintained instead of the full m x n grid
 *
 * Runtime : 2 ms
 * Memory  : 15.4 MB
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) dp[j] = dp[j-1] + grid[0][j];
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++)
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
        }
        return dp[n-1];
    }
};
