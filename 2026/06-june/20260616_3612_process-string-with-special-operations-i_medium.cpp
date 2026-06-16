/*
 * Problem #3612 - Process String with Special Operations I (Medium)
 * https://leetcode.com/problems/process-string-with-special-operations-i/
 *
 * Approach: Linear scan simulation using a mutable result string.
 * Each character is processed once: lowercase letters are appended, '*' removes
 * the last character, '#' doubles the string by appending it to itself, and '%'
 * reverses the entire result string in place.
 *
 * Time Complexity: O(n * m) where n is the length of s and m is the max length
 * of result; '#' and '%' operations iterate over result, making each potentially O(m).
 * Space Complexity: O(m) where m is the final length of the result string,
 * which can grow up to exponentially large due to '#' doubling.
 *
 * Runtime: 7 ms
 * Memory: 39.7 MB
 */

class Solution {
public:
    string processStr(string s) {
        string result = "";

        for (char c : s) {
            if (islower(c))              result += c;
            else if (c == '*' && !result.empty()) result.pop_back();
            else if (c == '#')           result += result;
            else if (c == '%')           reverse(result.begin(), result.end());
        }
        return result;
    }
};
