/*
 * 1155. Number of Dice Rolls With Target Sum (Medium)
 * https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
 *
 * Approach: Bottom-up Dynamic Programming
 * Use a 1D DP array where dp[j] represents the number of ways to reach sum j using the dice rolled so far.
 * For each die, iterate over all possible sums and accumulate counts from all valid face values (1 to k), updating a new DP array to avoid using the same die twice.
 * All results are taken modulo 1e9+7 to prevent integer overflow.
 *
 * Time Complexity: O(n * target * k)
 *   - For each of the n dice, we iterate over target sums and up to k faces.
 *
 * Space Complexity: O(target)
 *   - Only two 1D arrays of size (target+1) are maintained at any time.
 *
 * Runtime: 19 ms
 * Memory: 13.1 MB
 */

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<long long> ndp(target + 1, 0);
            for (int j = 1; j <= target; j++) {
                for (int f = 1; f <= k && f <= j; f++) {
                    ndp[j] = (ndp[j] + dp[j-f]) % MOD;
                }
            }
            dp = ndp;
        }
        return dp[target];
    }
};
