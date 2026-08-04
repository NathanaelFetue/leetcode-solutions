/*
 * Problem #1143: Longest Common Subsequence (Medium)
 * https://leetcode.com/problems/longest-common-subsequence/
 *
 * Approach: Space-Optimized Dynamic Programming
 * Instead of maintaining a full 2D DP table, we use two 1D arrays (prev and curr)
 * to represent the previous and current rows. For each pair of characters, if they
 * match we extend the diagonal value (prev[j-1]+1), otherwise we take the max of
 * the left (curr[j-1]) or top (prev[j]) neighbor, reducing space from O(m*n) to O(max(m,n)).
 *
 * Time Complexity : O(m * n) - iterating over all pairs of characters in both strings
 * Space Complexity: O(max(m, n)) - two 1D arrays of size max(m+1, n+1) instead of a 2D table
 *
 * Runtime : 23 ms
 * Memory  : 26.6 MB
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() , n = text2.size();
        vector<int> prev(max(m+1,n+1) , 0) , curr(max(m+1,n+1) , 0);

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++) {
                if(text1[i-1] == text2[j-1]) {
                    curr[j] = prev[j-1] +1;
                } else {
                    curr[j] = max(curr[j-1] , prev[j]);
                }
            }
            prev = curr ;
            vector<int> curr(max(m+1,n+1) ,0);
        }

        return prev[n];
    }
};
