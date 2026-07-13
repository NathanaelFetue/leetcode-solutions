/*
 * Problem #1291 - Sequential Digits (Medium)
 * URL: https://leetcode.com/problems/sequential-digits/
 *
 * Approach/Algorithm:
 * Use the fixed string "123456789" as a source of all possible sequential digit sequences.
 * For every possible length (2 to 9) and every valid starting position within that string,
 * extract the substring, convert it to an integer, and collect those that fall within [low, high].
 * This guarantees results are naturally produced in ascending order without sorting.
 *
 * Time Complexity: O(1) - There are at most 8+7+6+...+1 = 36 substrings to evaluate,
 * which is a constant number of operations regardless of input.
 *
 * Space Complexity: O(1) - Excluding the output vector, only a constant-size string
 * and a fixed number of loop variables are used.
 *
 * Runtime: 0 ms
 * Memory: 8.3 MB
 */

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string digits = "123456789";

        for (int len = 2; len <= 9; len++) {
            for (int start = 0; start + len <= 9; start++) {
                int num = stoi(digits.substr(start, len));
                if (num >= low && num <= high)
                    res.push_back(num);
            }
        }
        return res;
    }
};
