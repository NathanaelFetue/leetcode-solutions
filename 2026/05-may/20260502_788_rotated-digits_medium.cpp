/*
 * Problem #788 - Rotated Digits (Medium)
 * https://leetcode.com/problems/rotated-digits/
 *
 * Approach: Brute-force digit validation using a precomputed rotation map.
 * For each number from 1 to n, extract its digits and check that every digit
 * is valid when rotated (exists in {0,1,2,5,6,8,9}) and that at least one digit
 * actually changes value under rotation (i.e., the number differs from its rotated form).
 * Digits 3, 4, and 7 immediately disqualify a number.
 *
 * Time Complexity : O(n * log10(n)) — for each of the n numbers, we process
 *                   its O(log10(n)) digits.
 * Space Complexity: O(log10(n)) — for storing the digit array of each number;
 *                   the rotation map is fixed-size O(1).
 *
 * Runtime : 80 ms
 * Memory  : 24.8 MB
 */

class Solution {
public:
    unordered_map<int, int> val = {
        {0, 0},
        {1, 1},
        {2, 5},
        {5, 2},
        {6, 9},
        {8, 8},
        {9, 6}
    };

    vector<int> digits(int n) {
        vector<int> dig;
        while (n > 0) {
            dig.push_back(n % 10);
            n /= 10;
        }
        reverse(dig.begin(), dig.end());
        return dig;
    }

    bool isGood(int n) {
        vector<int> dig = digits(n);

        bool changed = false;

        for (auto d : dig) {
            if (val.count(d) == 0) return false;
            if (val[d] != d) {
                changed = true;
            }
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
