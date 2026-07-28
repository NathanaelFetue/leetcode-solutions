/*
 * Problem 3517: Smallest Palindromic Rearrangement I (Medium)
 * https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
 *
 * Approach/Algorithm:
 * Since the input string is already a palindrome, we only need to rearrange the first half
 * to form the lexicographically smallest palindrome. Sort the left half of the string to get
 * the smallest order, preserve the middle character if the length is odd, then mirror the
 * sorted left half to construct the right half.
 *
 * Time Complexity: O(n log n) — sorting the left half of length n/2 dominates.
 * Space Complexity: O(n) — storing the left half, optional middle character, and right half.
 *
 * Runtime: 89 ms
 * Memory: 71.3 MB
 */

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        string left = s.substr(0 , n/2);
        sort(left.begin() , left.end());
        string mid = (n % 2 == 1) ? string(1, s[n/2]) : "";
        string rigth = left;
        reverse(rigth.begin(), rigth.end());
        return left + mid + rigth;
    }
};
