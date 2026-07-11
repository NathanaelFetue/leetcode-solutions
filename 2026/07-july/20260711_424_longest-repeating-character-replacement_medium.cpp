/*
 * Problem #424 - Longest Repeating Character Replacement (Medium)
 * https://leetcode.com/problems/longest-repeating-character-replacement/
 *
 * Approach: Sliding Window with Character Frequency Map
 * Maintain a sliding window [l, r] and track the frequency of the most common character
 * within the window. If (window size - maxFreq) exceeds k, shrink the window from the
 * left, since we can only replace at most k characters to make the window uniform.
 *
 * Key Insight: The window is valid as long as (r - l + 1) - maxFreq <= k, meaning
 * the number of characters needing replacement does not exceed k.
 *
 * Time Complexity : O(n) - each character is visited at most twice (once by r, once by l)
 * Space Complexity: O(1) - the hash map holds at most 26 entries (uppercase English letters)
 *
 * Runtime : 7 ms
 * Memory  : 11.1 MB
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0, best = 0, maxFreq = 0;

        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);

            while ((r - l + 1) - maxFreq > k) {
                mp[s[l]]--;
                l++;
            }
            best = max(best, r - l + 1);
        }
        return best;
    }
};
