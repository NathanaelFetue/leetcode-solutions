/*
 * Problem #62 - Unique Paths (Medium)
 * https://leetcode.com/problems/unique-paths/
 *
 * Approach: 1D Dynamic Programming
 * We reduce the 2D DP table to a single 1D array of size n, initialized to 1
 * (representing the top row where only one path exists). For each subsequent row,
 * we update dp[j] in-place by adding dp[j-1] (paths from the left), effectively
 * accumulating the total unique paths to reach each cell from the top-left corner.
 *
 * Time Complexity : O(m * n) - we iterate over every cell in the m x n grid once.
 * Space Complexity: O(n) - only a single 1D array of length n is maintained.
 *
 * Runtime : 0 ms
 * Memory  : 8.4 MB
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[j] += dp[j-1];
        return dp[n-1];
    }
};
