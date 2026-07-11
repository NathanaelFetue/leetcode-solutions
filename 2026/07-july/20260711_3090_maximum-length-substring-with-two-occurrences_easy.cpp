/*
 * Problem #3090 - Maximum Length Substring With Two Occurrences
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
 *
 * Approach: Sliding Window with Hash Map
 * Use a sliding window defined by two pointers (l, r) and a hash map to track
 * character frequencies. Expand the window by moving r right, and shrink it by
 * advancing l whenever any character exceeds 2 occurrences. Track the maximum
 * valid window length throughout the traversal.
 *
 * Time Complexity: O(n) - each character is visited at most twice (once by r, once by l)
 * Space Complexity: O(1) - the hash map holds at most 26 lowercase English letters
 *
 * Runtime: 2 ms
 * Memory: 9.5 MB
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
