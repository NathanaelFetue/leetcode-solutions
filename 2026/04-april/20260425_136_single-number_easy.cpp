/*
 * Problem #136 - Single Number (Easy)
 * https://leetcode.com/problems/single-number/
 *
 * Approach: Bitwise XOR traversal.
 * XOR of a number with itself is 0, and XOR of any number with 0 is the number itself.
 * By XORing all elements together, every duplicate pair cancels out, leaving only the single number.
 *
 * Time Complexity: O(n) - single pass through all n elements in the array.
 * Space Complexity: O(1) - only one integer variable used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 20.7 MB
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int x : nums) res ^= x;
        return res;
    }
};
