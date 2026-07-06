/*
 * Problem #1653 - Minimum Deletions to Make String Balanced (Medium)
 * URL: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
 *
 * Approach: Dynamic Programming with 'b' count tracking.
 * dp[i] represents the minimum deletions to make s[0..i] balanced.
 * For each 'b', dp[i] = dp[i-1] (no deletion needed). For each 'a', dp[i] = min(dp[i-1]+1, countB),
 * choosing between deleting the current 'a' or deleting all 'b's seen so far.
 *
 * Time Complexity: O(n) - single pass through the string of length n.
 * Space Complexity: O(n) - dp array of size n.
 *
 * Runtime: 23 ms
 * Memory: 40.6 MB
 */

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        
        int countB = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'b') {
                countB++;
                dp[i] = (i > 0 ? dp[i-1] : 0);
            } else {
                dp[i] = min((i > 0 ? dp[i-1] : 0) + 1, countB);
            }
        }
        return dp[n-1];
    }
};
