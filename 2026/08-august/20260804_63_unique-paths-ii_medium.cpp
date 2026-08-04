/*
 * Problem #63: Unique Paths II (Medium)
 * https://leetcode.com/problems/unique-paths-ii/
 *
 * Approach: 1D Dynamic Programming with obstacle handling.
 * We use a single DP array of size n where dp[j] represents the number of unique paths
 * to reach column j in the current row. For each cell, if it contains an obstacle we set
 * dp[j] = 0; otherwise we accumulate paths from the left (dp[j-1]), while the top paths
 * are carried implicitly from the previous row iteration.
 *
 * Time Complexity : O(m * n) — we iterate over every cell in the grid exactly once.
 * Space Complexity: O(n) — only a single 1D array of length n is used instead of a full 2D grid.
 *
 * Runtime : 0 ms
 * Memory  : 11.6 MB
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] ==1) return 0;
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i=0; i< m; i++){
            for(int j = 0; j<n; j++){
                if(obstacleGrid[i][j] == 1) dp[j] = 0;
                else if (j>0) dp[j] += dp[j-1];
            }
        }

       return dp[n-1]; 
    }
};
