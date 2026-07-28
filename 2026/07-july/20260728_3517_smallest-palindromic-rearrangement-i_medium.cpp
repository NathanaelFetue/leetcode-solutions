/*
 * Problem #3517: Smallest Palindromic Rearrangement I (Medium)
 * URL: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
 *
 * Approach: Greedy Sort on Half
 * Since the input string is guaranteed to be a palindrome, extract the left half,
 * sort it in ascending order to get the lexicographically smallest arrangement,
 * then mirror it to form the right half. If the length is odd, preserve the middle character.
 * This works because sorting the left half and reflecting it produces the smallest valid palindrome.
 *
 * Time Complexity: O(n log n) — dominated by sorting the left half of length n/2.
 * Space Complexity: O(n) — for storing the left, mid, and right substrings.
 *
 * Runtime: 107 ms
 * Memory: 71.4 MB
 */

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string left = s.substr(0, n / 2);
        
        sort(left.begin(), left.end());
    
        string right = left;
        reverse(right.begin(), right.end());
        
        string mid = (n % 2 == 1) ? string(1, s[n/2]) : "";
        
        return left + mid + right;
    }
};
