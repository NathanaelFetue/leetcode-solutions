/*
 * 877. Stone Game - Medium
 * https://leetcode.com/problems/stone-game/
 *
 * Approach: Interval Dynamic Programming
 * dp[i][j] represents the maximum score difference (current player minus opponent)
 * for the subarray piles[i..j]. At each step, the current player picks either the
 * leftmost or rightmost pile, and the opponent plays optimally on the remaining
 * subarray. The recurrence is: dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]).
 * Alice wins if dp[0][n-1] > 0, meaning she achieves a strictly positive score advantage.
 *
 * Time Complexity : O(n^2) - filling an n x n DP table, each cell in O(1)
 * Space Complexity: O(n^2) - for the 2D DP table of size n x n
 *
 * Runtime : 10 ms
 * Memory  : 19.5 MB
 */

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // dp[i][j] = max score difference (current player - opponent) 
        // for subarray piles[i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: single pile, current player takes it
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }
        
        // Fill by increasing length of subarray
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                // Take from left: piles[i] - dp[i+1][j] (opponent's best on remaining)
                // Take from right: piles[j] - dp[i][j-1]
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
            }
        }
        
        return dp[0][n-1] > 0;
    }
};
