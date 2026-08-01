/*
 * Problem #486 - Predict the Winner
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/predict-the-winner/
 *
 * Approach: 1D Dynamic Programming (space-optimized interval DP)
 * The dp array tracks the score difference (current player score minus opponent score)
 * for every subarray. For each interval [i, j], dp[j] is updated to the maximum
 * score difference the current player can achieve by choosing either end of the array.
 * If the total number of elements is even, the first player always wins by symmetry.
 *
 * Time Complexity: O(n^2) - two nested loops iterate over all subarray intervals.
 * Space Complexity: O(n) - a single 1D dp array of size n is used instead of a 2D table.
 *
 * Runtime: 0 ms
 * Memory: 9.7 MB
 */

class Solution {
public:
    bool predictTheWinner(vector<int>& A) {
        int n = A.size();
        if (~n & 1) return true;

        vector<int> dp(n);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = A[i];
            for (int j = i + 1; j < n; j++)
                dp[j] = max(A[i] - dp[j], A[j] - dp[j - 1]);
        }

        return dp[n - 1] >= 0;
    }
};
