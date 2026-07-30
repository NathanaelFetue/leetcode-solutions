/*
 * Problem 3014: Minimum Number of Pushes to Type Word I
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
 *
 * Approach: Greedy index-based calculation.
 * The 8 keys on the phone can each hold multiple letters, where the 1st letter costs 1 push,
 * the 2nd costs 2 pushes, etc. By assigning letters greedily in order, the i-th letter (0-indexed)
 * belongs to key group (i / 8), costing (i / 8 + 1) pushes. Summing these values gives the answer.
 *
 * Time Complexity: O(n) - single pass over all n characters in the word.
 * Space Complexity: O(1) - only a constant number of variables are used.
 *
 * Runtime: 0 ms
 * Memory: 8.3 MB
 */

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += i / 8 + 1;
        }
        return ans;
    }
};
