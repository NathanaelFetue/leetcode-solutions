/*
 * Problem #1291 - Sequential Digits (Medium)
 * https://leetcode.com/problems/sequential-digits/
 *
 * Approach: Sliding Window over '123456789' String
 * Use the string '123456789' as a source of all possible sequential digit sequences.
 * For each valid length (2 to 9), slide a window across the string to extract substrings,
 * convert them to integers, and collect those that fall within [low, high].
 * Iterating by length first ensures the result is naturally sorted in ascending order.
 *
 * Time Complexity: O(1) - At most 8+7+6+...+1 = 36 substrings are evaluated, a fixed constant.
 * Space Complexity: O(1) - Output aside, only a fixed-size string and loop variables are used.
 *
 * Runtime : 0 ms
 * Memory  : 8.3 MB
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
