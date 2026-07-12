/*
 * 567. Permutation in String - Medium
 * https://leetcode.com/problems/permutation-in-string/
 *
 * Approach: Sliding Window with Hash Map Comparison
 * Maintain a fixed-size sliding window of length s1.size() over s2, tracking character
 * frequencies in the window using an unordered_map. At each step, add the new right
 * character and evict the leftmost character once the window exceeds the target size,
 * then compare the window map directly against the prebuilt frequency map of s1.
 *
 * Time Complexity : O(n) - single pass over s2 of length n; map comparison is O(26) = O(1)
 *                   since the alphabet is fixed size.
 * Space Complexity: O(1) - both maps hold at most 26 distinct lowercase characters,
 *                   so space is bounded by the alphabet size regardless of input length.
 *
 * Runtime : 11 ms
 * Memory  : 10.8 MB
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char,int> need, window;
        for (char c : s1) need[c]++;

        int k = s1.size();

        for (int r = 0; r < s2.size(); r++) {
            window[s2[r]]++;

            if (r >= k) {
                char left = s2[r - k];
                window[left]--;
                if (window[left] == 0) window.erase(left);
            }

            if (window == need) return true;
        }
        return false;
    }
};
