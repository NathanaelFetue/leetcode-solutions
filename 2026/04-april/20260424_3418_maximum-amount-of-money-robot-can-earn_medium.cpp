/*
 * Problem #3418: Maximum Amount of Money Robot Can Earn (Medium)
 * https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/
 *
 * Approach: 3D Dynamic Programming
 * dp[i][j][k] represents the maximum coins collectible reaching cell (i,j)
 * having used k skip-moves (neutralizing negative cells) so far (k in {0,1,2}).
 * At each cell, the robot arrives from above or from the left; if the current
 * cell is negative and k > 0, it may skip adding that cell's value by using
 * one neutralization from the previous state with k-1 skips used.
 * The answer is the maximum of dp[m-1][n-1][0..2].
 *
 * Time Complexity : O(m * n * 3) = O(m * n) — each cell visited once per skip state.
 * Space Complexity: O(m * n * 3) = O(m * n) — 3D DP table of size m x n x 3.
 *
 * Runtime : 547 ms
 * Memory  : 316.8 MB
 */

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        const long long NEG_INF = LLONG_MIN / 2;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, NEG_INF)));

        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = max((long long)coins[0][0], 0LL);
        dp[0][0][2] = max((long long)coins[0][0], 0LL);

        for (int j = 1; j < n; j++) {
            for (int k = 0; k < 3; k++) {
                if (dp[0][j-1][k] == NEG_INF) continue;
                dp[0][j][k] = dp[0][j-1][k] + coins[0][j];
                if (coins[0][j] < 0 && k > 0 && dp[0][j-1][k-1] != NEG_INF)
                    dp[0][j][k] = max(dp[0][j][k], dp[0][j-1][k-1]);
            }
        }

        for (int i = 1; i < m; i++) {
            for (int k = 0; k < 3; k++) {
                if (dp[i-1][0][k] == NEG_INF) continue;
                dp[i][0][k] = dp[i-1][0][k] + coins[i][0];
                if (coins[i][0] < 0 && k > 0 && dp[i-1][0][k-1] != NEG_INF)
                    dp[i][0][k] = max(dp[i][0][k], dp[i-1][0][k-1]);
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    long long prev = max(dp[i-1][j][k], dp[i][j-1][k]);
                    if (prev == NEG_INF) continue;
                    dp[i][j][k] = prev + coins[i][j];
                    if (coins[i][j] < 0 && k > 0) {
                        long long prevK = max(dp[i-1][j][k-1], dp[i][j-1][k-1]);
                        if (prevK != NEG_INF)
                            dp[i][j][k] = max(dp[i][j][k], prevK);
                    }
                }
            }
        }

        return (int)max(dp[m-1][n-1][0], max(dp[m-1][n-1][1], dp[m-1][n-1][2]));
    }
};
