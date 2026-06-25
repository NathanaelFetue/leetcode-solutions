/*
 * Problem #5 - Longest Palindromic Substring (Medium)
 * https://leetcode.com/problems/longest-palindromic-substring/
 *
 * Approach: Manacher's Algorithm
 * The input string is transformed by inserting '#' separators and sentinel characters ('^', '$')
 * to handle both odd and even length palindromes uniformly. Manacher's algorithm then computes
 * the palindrome radius array p[] in linear time by reusing previously computed palindrome
 * information via a tracked rightmost boundary and its center, avoiding redundant comparisons.
 *
 * Time Complexity: O(n) - each character is visited at most twice across all expansions
 * due to the center/right boundary optimization in Manacher's algorithm.
 *
 * Space Complexity: O(n) - the transformed string t and radius array p[] each grow
 * linearly with the size of the input string.
 *
 * Runtime: 4 ms
 * Memory: 11.4 MB
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        string t = "^";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";

        int m = t.size();
        vector<int> p(m, 0);
        int center = 0, right = 0;
        for (int i = 1; i < m - 1; i++) {
            int mirror = 2 * center - i;

            if (i < right)
                p[i] = min(right - i, p[mirror]);
            while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
                p[i]++;
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }
        int maxLen = 0, centerIndex = 0;
        for (int i = 1; i < m - 1; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }
        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};

