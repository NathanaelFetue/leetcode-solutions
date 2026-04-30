/*
 * Problem #3742 - Maximum Path Score in a Grid
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/maximum-path-score-in-a-grid/
 *
 * Approach: 3D Dynamic Programming
 * We define dp[i][j][c] as the maximum score achievable at cell (i,j) using exactly c 'cost units',
 * where each cell with grid value >= 1 contributes a cost of 1. We traverse the grid top-left to
 * bottom-right, updating each cell by arriving from above or from the left, accumulating the cell's
 * score whenever the remaining budget allows. The answer is the maximum value across all cost budgets
 * at the bottom-right cell.
 *
 * Time Complexity: O(m * n * k) - we iterate over all cells and all cost levels 0..k
 * Space Complexity: O(m * n * k) - 3D DP table of dimensions m x n x (k+1)
 *
 * Runtime: 865 ms
 * Memory: 499.5 MB
 */

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // dp[i][j][c] = max score en (i,j) avec coût c
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        dp[0][0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cost  = (grid[i][j] >= 1) ? 1 : 0;
                int score = grid[i][j];
                for (int c = cost; c <= k; c++) {
                    // venir du haut
                    if (i > 0 && dp[i-1][j][c-cost] != -1)
                        dp[i][j][c] = max(dp[i][j][c], dp[i-1][j][c-cost] + score);
                    // venir de la gauche
                    if (j > 0 && dp[i][j-1][c-cost] != -1)
                        dp[i][j][c] = max(dp[i][j][c], dp[i][j-1][c-cost] + score);
                    // cas (0,0)
                    if (i == 0 && j == 0) dp[i][j][0] = 0;
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++)
            ans = max(ans, dp[m-1][n-1][c]);
        return ans;
    }
};
