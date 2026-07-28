/*
 * Problem #3517 - Smallest Palindromic Rearrangement I (Medium)
 * https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
 *
 * Approach: Since the input string is guaranteed to be a palindrome, the first half
 * already contains the characters needed to form the left half of the result. We sort
 * the left half lexicographically to get the smallest arrangement, then mirror it to
 * form the right half, preserving the middle character if the length is odd.
 *
 * Algorithm:
 * 1. Extract the left half of the palindrome.
 * 2. Sort it to produce the lexicographically smallest sequence.
 * 3. Reverse the sorted left half to form the right half.
 * 4. Concatenate left + optional middle character + right.
 *
 * Time Complexity : O((n/2) log(n/2)) — dominated by sorting the left half of length n/2.
 * Space Complexity : O(n) — for storing left, right, mid, and the result string.
 *
 * Runtime : 74 ms
 * Memory  : 71.4 MB
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
