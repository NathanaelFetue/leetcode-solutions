/*
 * Problem #58 - Length of Last Word
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/length-of-last-word/
 *
 * Approach: Two-pass linear scan from the end of the string.
 * First, skip any trailing spaces by decrementing the index.
 * Then, count consecutive non-space characters until a space or the start of the string is reached.
 *
 * Time Complexity: O(n) - in the worst case we traverse the entire string (e.g., all spaces or one long word).
 * Space Complexity: O(1) - only a constant number of integer variables are used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 8.9 MB
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
