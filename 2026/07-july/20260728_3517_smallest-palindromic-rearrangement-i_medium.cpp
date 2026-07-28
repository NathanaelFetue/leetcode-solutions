/*
 * Problem #3517: Smallest Palindromic Rearrangement I (Medium)
 * URL: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
 *
 * Approach: Frequency Count + Greedy Construction
 * Count character frequencies, then greedily build the lexicographically smallest palindrome.
 * The left half is built by taking floor(freq/2) of each character in alphabetical order,
 * any character with an odd frequency becomes the middle character, and the right half
 * is the reverse of the left half.
 *
 * Time Complexity: O(n + 26) = O(n)
 *   - O(n) to count frequencies, O(26) to iterate alphabet and build the result.
 *
 * Space Complexity: O(n)
 *   - O(n) for the output string (left, mid, right), O(26) for the frequency map.
 *
 * Runtime: 58 ms | Memory: 82.3 MB
 */

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for (char c : s) mp[c]++;
        string left = "", mid = "";

        for (char c = 'a'; c <= 'z'; c++) {
            if (mp[c] % 2 == 1) mid = c;        
            left += string(mp[c] / 2, c);
        }
        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
