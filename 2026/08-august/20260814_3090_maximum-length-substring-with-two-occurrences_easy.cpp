/*
 * Problem 3090: Maximum Length Substring With Two Occurrences
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
 *
 * Approach:
 * The problem asks for the longest substring containing at most two occurrences of any character. The key insight is to use a sliding window with two pointers to maintain a contiguous valid window. By incrementally expanding the right pointer, we add characters to a frequency map; if any character's frequency exceeds two, we shrink the window from the left until the constraint is satisfied again. This greedy expansion and localized shrinking ensures we find the global maximum window size in a single pass without redundant re-evaluation.
 *
 * Time Complexity: O(N) — Both the left and right pointers traverse the string of length N at most once. Each character is inserted and removed from the frequency map at most once, making the overall time complexity linear.
 * Space Complexity: O(1) — The frequency map stores at most 26 unique lowercase English alphabets. Because the character set is bounded and small, the auxiliary space used is constant.
 *
 * Runtime: 4 ms | Memory: 9.6 MB
 */

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        int maxLength = 0;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            mp[s[r]]++;
            while (mp[s[r]] > 2) {
                mp[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
