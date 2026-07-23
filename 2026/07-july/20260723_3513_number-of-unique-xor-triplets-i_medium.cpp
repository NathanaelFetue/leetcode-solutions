/*
 * Problem #3513 - Number of Unique XOR Triplets I
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/number-of-unique-xor-triplets-i/
 *
 * Approach: Mathematical / Bit Manipulation
 * The key insight is that when nums contains more than 2 elements, the number of unique XOR
 * values achievable by triplets (i < j < k) from a permutation of 1..n is exactly 2^(bit_length(n)).
 * This is because XOR combinations of numbers 1..n can produce all values in the range [0, 2^bits - 1],
 * where bits is the number of bits needed to represent n. For n <= 2, the answer is simply n.
 *
 * Time Complexity: O(log n) - countBits iterates over the bits of n
 * Space Complexity: O(1) - only a constant amount of extra space is used
 *
 * Runtime: 0 ms
 * Memory: 199 MB
 */

class Solution {
public:
    int countBits(int n) {
        int bits = 0;
        while (n > 0) {
            bits++;
            n >>= 1;
        }
        return bits;
    }
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;

        return pow(2,countBits(n));
    }
};
