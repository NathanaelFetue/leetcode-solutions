/*
 * Problem #72 - Edit Distance (Medium)
 * https://leetcode.com/problems/edit-distance/
 *
 * Approach: Bottom-up Dynamic Programming (Wagner-Fischer algorithm).
 * Build a 2D DP table where dp[i][j] represents the minimum edit distance
 * between the first i characters of word1 and the first j characters of word2.
 * If characters match, inherit the diagonal value; otherwise take the minimum
 * of insert (dp[i][j-1]), delete (dp[i-1][j]), or replace (dp[i-1][j-1]) plus 1.
 *
 * Time Complexity : O(m * n) - fill every cell of the m+1 by n+1 DP table.
 * Space Complexity: O(m * n) - 2D DP table of size (m+1) x (n+1).
 *
 * Runtime : 4 ms
 * Memory  : 13 MB
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size() , n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i=0; i<=n; i++) dp[0][i] = i;
        for(int j=0; j<= m; j++) dp[j][0] = j;

        for(int i=1; i<=m; i++){
            for(int j =1; j<=n ; j++) {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min (dp[i][j-1] , min(dp[i-1][j] , dp[i-1][j-1])) + 1;
            }
        }

        return dp[m][n];
    }
};
