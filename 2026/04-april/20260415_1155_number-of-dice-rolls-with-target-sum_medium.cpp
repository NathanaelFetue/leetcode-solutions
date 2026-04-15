/*
 * 1155. Number of Dice Rolls With Target Sum - Medium
 * https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
 *
 * Approach: Bottom-up 2D dynamic programming where dp[i][j] represents the number
 * of ways to reach sum j using exactly i dice. For each die i and each possible
 * sum j, iterate over all valid face values f (1 to k) and accumulate dp[i-1][j-f].
 * All results are taken modulo 1e9+7 to prevent overflow.
 *
 * Time Complexity : O(n * target * k) - three nested loops over dice count, target
 *                   sum, and face values respectively.
 * Space Complexity: O(n * target) - 2D DP table of size (n+1) x (target+1).
 *
 * Runtime : 20 ms
 * Memory  : 13.4 MB
 */

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int f = 1; f <= k && f <= j; f++) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-f]) % MOD;
                }
            }
        }
        return dp[n][target];
    }
};
