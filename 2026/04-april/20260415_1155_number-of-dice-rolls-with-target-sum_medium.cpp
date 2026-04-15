/*
 * 1155. Number of Dice Rolls With Target Sum - Medium
 * https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
 *
 * Approach: Bottom-up dynamic programming where dp[j] represents the number of ways
 * to reach sum j using the dice rolled so far. For each die, we build a new DP array
 * by iterating over all possible sums and adding contributions from each face value (1 to k).
 * At each step, ndp[j] accumulates dp[j-f] for all valid face values f, effectively
 * counting all combinations that sum to j after rolling i dice.
 *
 * Time Complexity: O(n * target * k) - for each of n dice, we iterate over target sums
 * and for each sum consider up to k faces.
 *
 * Space Complexity: O(target) - two 1D arrays of size target+1 are used (current and next).
 *
 * Runtime: 19 ms
 * Memory: 13 MB
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
