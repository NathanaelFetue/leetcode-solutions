/*
 * Problem #3290 - Maximum Multiplication Score
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/maximum-multiplication-score/
 *
 * Approach: Dynamic Programming (1D DP with reverse iteration)
 * We use a DP array of size 5 where dp[j] represents the maximum score achievable
 * by selecting exactly j elements from array b (in order) paired with a[0..j-1].
 * For each element x in b, we iterate j from 4 down to 1 to avoid reusing the
 * same b element twice, updating dp[j] = max(dp[j], dp[j-1] + a[j-1] * x).
 * This ensures we select exactly 4 elements from b while preserving relative order.
 *
 * Time Complexity: O(n * 4) = O(n), where n is the length of array b.
 * Space Complexity: O(1), only a constant-size DP array of length 5 is used.
 *
 * Runtime: 1 ms | Memory: 139 MB
 */

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long long> dp(5, LLONG_MIN / 2);
        dp[0] = 0;
        for (int x : b) {
            for (int j = 4; j >= 1; j--) {
                if (dp[j-1] != LLONG_MIN / 2)
                    dp[j] = max(dp[j], dp[j-1] + (long long)a[j-1] * x);
            }
        }
        return dp[4];
    }
};
