/*
 * Problem #125 - Valid Palindrome (Easy)
 * https://leetcode.com/problems/valid-palindrome/
 *
 * Approach: Two-pointer technique with in-place alphanumeric filtering.
 * Left and right pointers move inward, skipping non-alphanumeric characters.
 * At each valid pair, characters are compared case-insensitively; mismatch returns false immediately.
 *
 * Time Complexity: O(n) - each character is visited at most once by the two pointers.
 * Space Complexity: O(1) - no extra data structures used; comparisons done in-place.
 *
 * Runtime: 0 ms
 * Memory: 9.8 MB
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;

            if (tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
