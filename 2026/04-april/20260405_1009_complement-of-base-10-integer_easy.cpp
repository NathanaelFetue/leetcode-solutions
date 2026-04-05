/*
 * Problem 1009: Complement of Base 10 Integer (Easy)
 * https://leetcode.com/problems/complement-of-base-10-integer/
 *
 * Approach: Bit Manipulation with XOR Masking
 * First, handle the edge case where n == 0 by returning 1 directly.
 * Determine the number of bits in n using __lg(n)+1, then construct a mask
 * of all 1s with that many bits via (1 << bits) - 1, and XOR n with the mask
 * to flip all relevant bits, producing the complement.
 *
 * Time Complexity : O(1) - all operations (log2, shift, XOR) are constant time.
 * Space Complexity: O(1) - only a fixed number of integer variables are used.
 *
 * Runtime : 0 ms
 * Memory  : 7.8 MB
 */

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int bits = __lg(n) +1;
        int flipped = n ^((1 <<bits) -1);
        return flipped;
    }
};
