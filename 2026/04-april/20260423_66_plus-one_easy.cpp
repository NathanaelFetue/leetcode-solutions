/*
 * Problem #66 - Plus One (Easy)
 * https://leetcode.com/problems/plus-one/
 *
 * Approach: Right-to-left digit traversal with early return.
 * Iterate from the last digit backward; if a digit is less than 9, increment it
 * and return immediately. If it equals 9, set it to 0 and continue carrying.
 * If all digits were 9 (loop exhausts), prepend a 1 to handle the overflow case (e.g., 999 -> 1000).
 *
 * Time Complexity : O(n) - in the worst case (all 9s), every digit is visited once.
 * Space Complexity : O(1) - modification is done in-place; the insert in the worst case
 *                    is O(n) for shifting, but no auxiliary data structure is used.
 *
 * Runtime : 1 ms
 * Memory  : 11.4 MB
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] < 9) { digits[i]++; return digits; }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
