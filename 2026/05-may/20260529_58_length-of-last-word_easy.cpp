/*
 * Problem 58: Length of Last Word
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/length-of-last-word/
 *
 * Approach: Two-pass linear scan from the end of the string.
 * First, skip any trailing whitespace by decrementing the index.
 * Then, count consecutive non-space characters until a space or the start of the string is reached.
 *
 * Time Complexity: O(n) in the worst case, where n is the length of the string,
 * as we may scan the entire string if it consists mostly of spaces.
 *
 * Space Complexity: O(1) — only a constant amount of extra space is used
 * regardless of the input size.
 *
 * Runtime: 2 ms | Memory: 8.7 MB
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int count = 0;

        while (i >= 0 && s[i] == ' ') i--;

        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        return count;
    }
};
