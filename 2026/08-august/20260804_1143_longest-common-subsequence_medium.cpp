/*
 * Problem #1143: Longest Common Subsequence (Medium)
 * https://leetcode.com/problems/longest-common-subsequence/
 *
 * Approach: Space-optimized dynamic programming using two 1D rolling arrays (prev and curr)
 * instead of a full 2D DP table. For each pair of characters, if they match we extend the
 * diagonal (prev[j-1] + 1), otherwise we take the max of left (curr[j-1]) or top (prev[j]).
 * After each row, curr is copied into prev, effectively sliding the window forward.
 *
 * Time Complexity : O(m * n) - two nested loops iterating over all character pairs
 *                   where m = len(text1), n = len(text2)
 * Space Complexity: O(min(m, n)) - only two 1D arrays of size max(m,n)+1 are maintained
 *                   instead of a full m x n matrix
 *
 * Runtime : 15 ms
 * Memory  : 9 MB
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
        }

        return prev[n];
    }
};
