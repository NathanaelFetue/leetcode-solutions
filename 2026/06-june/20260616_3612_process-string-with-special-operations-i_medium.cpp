/*
 * Problem #3612 - Process String with Special Operations I
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/process-string-with-special-operations-i/
 *
 * Approach/Algorithm:
 * Iterates through the input string character by character, maintaining a result string.
 * Lowercase letters are appended directly; '#' doubles the result by appending it to itself;
 * '%' reverses the entire result; '*' removes the last character if the result is non-empty.
 *
 * Time Complexity: O(n * m) where n is the length of s and m is the max length of result,
 * due to potential string doubling on '#' and reversal on '%'.
 *
 * Space Complexity: O(m) where m is the maximum size the result string can grow to,
 * proportional to the number of lowercase chars and '#' operations.
 *
 * Runtime: 3 ms
 * Memory: 39.7 MB
 */

class Solution {
public:
    string processStr(string s) {
        char last;
        string result = "";

        for(int i=0; i<s.length();i++){
            if(islower(s[i])) {
                result += s[i];
            }
            if(s[i] == '#') {
                result += result;
            }
            if(s[i] == '%') {
                reverse(result.begin() , result.end());
            }
            if(s[i] == '*' && result.length() >= 1) {
                result.pop_back();
            }
        }
        return result;;
    }
};
