/*
 * Problem #788 - Rotated Digits (Medium)
 * https://leetcode.com/problems/rotated-digits/
 *
 * Approach: Brute-force digit validation for each number from 1 to N.
 * For each number, extract digits one by one and check two conditions:
 * (1) no digit is 3, 4, or 7 (invalid when rotated), and (2) at least one
 * digit is 2, 5, 6, or 9 (ensures the rotated number differs from original).
 * Digits 0, 1, and 8 are neutral — they map to themselves and don't cause
 * the number to become 'different' after rotation.
 *
 * Time Complexity : O(N * log10(N)) — iterating over N numbers, each with
 *                   at most log10(N) digits to inspect.
 * Space Complexity: O(1) — only a few integer variables used, no extra storage.
 *
 * Runtime : 0 ms
 * Memory  : 7.9 MB
 */

class Solution {
public:

    bool isGood(int n) {
        bool changed = false;

        while (n > 0) {
            int d = n % 10;
            if (d == 3 || d == 4 || d == 7)
                return false;
            if (d == 2 || d == 5 || d == 6 || d == 9)
                changed = true;
            n /= 10;
        }

        return changed;
    }

    int rotatedDigits(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (isGood(i)) {
                count++;
            }
        }

        return count;
    }
};
