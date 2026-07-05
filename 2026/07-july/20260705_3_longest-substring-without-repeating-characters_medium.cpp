/*
 * Problem #3 - Longest Substring Without Repeating Characters (Medium)
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Approach: Sliding Window with Hash Map
 * Uses a two-pointer sliding window where the right pointer expands the window and the left
 * pointer jumps forward whenever a duplicate character is found within the current window.
 * The hash map stores the most recent index of each character, allowing O(1) duplicate detection
 * and immediate repositioning of the left boundary past the repeated character.
 *
 * Time Complexity : O(n) - each character is visited at most once by the right pointer
 * Space Complexity: O(min(m, n)) - hash map stores at most min(charset size m, string length n) entries
 *
 * Runtime : 14 ms
 * Memory  : 11.7 MB
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, best = 0;

        for (int r = 0; r < s.size(); r++) {
            if (mp.count(s[r]) && mp[s[r]] >= l)
                l = mp[s[r]] + 1;
            mp[s[r]] = r;
            best = max(best, r - l + 1);
        }
        return best;
    }
};
