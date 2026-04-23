/*
 * Problem #66 - Plus One
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/plus-one/
 *
 * Approach/Algorithm:
 * Uses a recursive strategy to simulate the carry propagation of adding one to a number
 * represented as a digit array. If the last digit is not 9, it simply increments it and returns.
 * If it is 9, it sets it to 0 and recursively calls plusOne on the prefix, handling the carry
 * all the way up, inserting a leading 1 if the entire array consists of nines.
 *
 * Time Complexity: O(n) - In the worst case (e.g., [9,9,9,...,9]), every digit is visited
 * once through recursion, where n is the number of digits.
 *
 * Space Complexity: O(n) - Recursive call stack depth is at most n, and subvectors of
 * diminishing size are created at each level.
 *
 * Runtime: 0 ms
 * Memory: 12.2 MB
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (digits[n-1] != 9) {
            digits[n-1]++;
            return digits;
        }
        digits[n-1] = 0;
        if (n == 1) {
            digits.insert(digits.begin(), 1);
            return digits;
        }
        vector<int> sub(digits.begin(), digits.end() - 1);
        sub = plusOne(sub);
        sub.push_back(0);
        return sub;
    }
};
