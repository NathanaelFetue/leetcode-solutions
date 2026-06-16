/*
 * Problem 3612: Process String with Special Operations I (Medium)
 * https://leetcode.com/problems/process-string-with-special-operations-i/
 *
 * Approach/Algorithm:
 * Iterate through each character of the input string and apply operations to a result buffer.
 * Lowercase letters are appended directly, '*' removes the last character, '#' doubles the string
 * by appending it to itself, and '%' reverses the current result in place.
 *
 * Time Complexity: O(n * m) where n is the length of s and m is the max length of result;
 * '#' can double the result size and '%' takes O(m) time, making the worst case exponential
 * in the number of '#' and '%' operations relative to the result length.
 *
 * Space Complexity: O(m) where m is the final length of the result string, bounded by
 * the transformations applied during processing.
 *
 * Runtime: 4 ms
 * Memory: 39.8 MB
 */

class Solution {
public:
    string processStr(string s) {
        string result = "";

        for (char c : s) {
            if (islower(c)) result += c;
            else if (c == '*' && !result.empty()) result.pop_back();
            else if (c == '#') result += result;
            else if (c == '%') reverse(result.begin(), result.end());
        }
        return result;
    }
};
