/*
 * Problem #136 - Single Number (Easy)
 * https://leetcode.com/problems/single-number/
 *
 * Approach: Bitwise XOR across all elements.
 * XOR of a number with itself is 0, and XOR with 0 is the number itself.
 * Since every duplicate appears exactly twice, all pairs cancel out, leaving only the unique element.
 *
 * Time Complexity: O(n) - single linear pass through the array of n elements.
 * Space Complexity: O(1) - only one integer variable is used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 20.6 MB
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (const int& x : nums) res ^= x;
        return res;
    }
};
