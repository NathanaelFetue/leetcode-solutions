/*
 * Problem #7 - Reverse Integer
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/reverse-integer/
 *
 * Approach/Algorithm:
 * The solution extracts digits one by one from the absolute value of the input using modulo
 * and division, building the reversed number iteratively. The sign is tracked separately and
 * reapplied after reversal. Overflow is handled by using a 64-bit long long and checking
 * against INT_MAX and INT_MIN before casting back to int, returning 0 if bounds are exceeded.
 *
 * Time Complexity: O(log10(x)) - we iterate once per digit in the input number.
 * Space Complexity: O(1) - only a fixed number of variables are used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 8.5 MB
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
