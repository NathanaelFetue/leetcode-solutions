/*
 * Problem 3702: Longest Subsequence With Non-Zero Bitwise XOR
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
 *
 * Approach:
 * The key insight lies in the algebraic properties of the bitwise XOR operation, specifically that removing a non-zero element from a zero-XOR set yields a non-zero XOR sum. If the XOR sum of the entire array is already non-zero, the longest subsequence is the array itself, yielding a length of N. If the total XOR sum is zero, we can transition to a non-zero state by excluding a single non-zero element, since 0 ^ y = y (which is non-zero). Thus, if the array contains at least one non-zero element, the optimal subsequence length is N - 1; otherwise, if the array is entirely comprised of zeros, no valid subsequence can be formed, yielding 0.
 *
 * Time Complexity: O(N) — a single linear scan is performed to compute the total XOR sum and check for the presence of any non-zero elements.
 * Space Complexity: O(1) — only a few scalar variables are used to track the XOR sum and the zero-element flag, requiring constant auxiliary space.
 *
 * Runtime: 0 ms | Memory: 171.2 MB
 */

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool allZero = true;

        for (int x : nums) {
            totalXor ^= x;
            if (x > 0) {
                allZero = false;
            }
        }

        if (totalXor > 0) {
            return n;
        }

        return allZero ? 0 : n - 1;
    }
};
