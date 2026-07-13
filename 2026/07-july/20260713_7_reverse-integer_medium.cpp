/*
 * Problem #7 - Reverse Integer
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/reverse-integer/
 *
 * Approach/Algorithm:
 * The solution extracts digits one by one from the absolute value of the input using modulo and integer division,
 * building the reversed number iteratively. A long long accumulator is used to safely detect overflow before
 * casting back to int, returning 0 if the result exceeds 32-bit signed integer bounds.
 *
 * Time Complexity: O(log10(x)) - the while loop iterates once per digit in the input number.
 * Space Complexity: O(1) - only a fixed number of variables are used, no extra data structures.
 *
 * Runtime: 2 ms
 * Memory: 8.6 MB
 */

class Solution {
public:
    int reverse(int x) {
        long long val = 0;
        bool neg = x < 0;
        long long n = abs((long long)x);

        while (n > 0) {
            val = val * 10 + n % 10;
            n /= 10;
        }
        val = neg ? -val : val;
        
        if (val > INT_MAX || val < INT_MIN) return 0;
        return (int)val;
    }
};
