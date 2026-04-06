/*
 * Problem 1758: Minimum Changes To Make Alternating Binary String
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
 *
 * Approach: Dual Pattern Comparison
 * There are exactly two valid alternating binary strings: one starting with '0' (010101...)
 * and one starting with '1' (101010...). We simultaneously count mismatches against both
 * patterns in a single pass, then return the minimum of the two mismatch counts.
 *
 * Time Complexity: O(n) - single linear pass through the string of length n.
 * Space Complexity: O(1) - only two integer counters used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 9.4 MB
 */

class Solution {
public:
    int minOperations(string s) {
        int cost1 = 0;
        int cost2 =0;
        if (s.empty()) return 0;
        if (s.size() == 1) return 0;
        for (int i =0; i < s.size(); i++) {
            char expected1 = (i%2 == 0) ? '0' : '1';
            char expected2 = (i%2 == 0) ? '1' : '0';
            if (s[i] != expected1) cost1++;
            if (s[i] != expected2) cost2++;
        }
        return min(cost1, cost2);
    }
};
