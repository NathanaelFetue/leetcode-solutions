/*
 * Problem 3517: Smallest Palindromic Rearrangement I (Medium)
 * https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
 *
 * Approach: Frequency Count + Greedy Construction
 * Count character frequencies using a hash map, then greedily build the smallest
 * palindrome by iterating 'a' to 'z', placing half of each character's count into
 * the left half. Any character with an odd frequency contributes to the middle.
 * The right half is simply the reverse of the left half.
 *
 * Time Complexity: O(n + 26) = O(n)
 *   - O(n) to count frequencies, O(26) to iterate alphabet and build left half.
 *
 * Space Complexity: O(n)
 *   - O(26) for the frequency map, O(n) for the output string construction.
 *
 * Runtime: 117 ms | Memory: 82.3 MB
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
