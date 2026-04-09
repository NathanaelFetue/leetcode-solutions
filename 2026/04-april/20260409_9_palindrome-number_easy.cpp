/*
 * Problem #9 - Palindrome Number (Easy)
 * https://leetcode.com/problems/palindrome-number/
 *
 * Approach: String Conversion with Reverse Comparison
 * Convert the integer to its string representation, then compare it against
 * its reverse using reverse iterators. Negative numbers are immediately
 * rejected via the x >= 0 guard since they can never be palindromes.
 *
 * Time Complexity: O(d) where d is the number of digits in x.
 * Building the string and constructing the reversed copy each take O(d),
 * and the equality comparison is also O(d).
 *
 * Space Complexity: O(d) for storing the original string and its reverse.
 *
 * Runtime : 0 ms
 * Memory  : 12.1 MB
 */

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        return x >= 0 && s == string(s.rbegin(), s.rend());
    }
};
