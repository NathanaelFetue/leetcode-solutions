/*
 * Problem #3954 - Sum of Compatible Numbers in Range I
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/
 *
 * Approach/Algorithm:
 * Iterate over all integers in the range [max(1, n-k), n+k] and check if each
 * candidate x is bitwise-compatible with n (i.e., (n & x) == 0, meaning no bit
 * positions overlap). Accumulate all such compatible values and return the sum.
 *
 * Time Complexity: O(k) — the loop runs over at most 2k+1 values centered on n,
 * so the number of iterations is linear in k.
 *
 * Space Complexity: O(1) — only a constant number of integer variables are used
 * regardless of input size.
 *
 * Runtime : 0 ms
 * Memory  : 8.6 MB
 */

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int cpt = 0;
        for (int x = max(1, n - k); x <= n + k; x++) {
            if ((n & x) == 0)
                cpt += x;
        }
        return cpt;
    }
};
