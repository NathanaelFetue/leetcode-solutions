/*
 * Problem #76 - Minimum Window Substring (Hard)
 * URL: https://leetcode.com/problems/minimum-window-substring/
 *
 * Approach: Sliding Window with Frequency Maps
 * Use two pointers (left, right) to maintain a sliding window over string s.
 * Expand the right pointer to include characters, then shrink from the left
 * whenever the window fully covers all characters in t (checked via frequency
 * map comparison). Track the smallest valid window seen during shrinking.
 *
 * Time Complexity: O(|s| * |t|) in the worst case — the covers() helper
 * iterates over all unique characters in t for each valid window state.
 * With optimization (a counter for matched chars), this can be reduced to O(|s| + |t|).
 *
 * Space Complexity: O(|s| + |t|) — two hash maps storing character frequencies
 * for the window and target string t.
 *
 * Runtime: 90 ms
 * Memory: 11.5 MB
 */

class Solution {
public:
    bool covers(unordered_map<char,int>& window, unordered_map<char,int>& mp) {
        for (auto& [c, freq] : mp)
            if (window[c] < freq) return false;
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char,int> mp, window;
        for (char c : t) mp[c]++;

        int left = 0;
        int bestLeft = -1, bestLen = INT_MAX;

        for (int r = 0; r < s.size(); r++) {
            if (mp.contains(s[r]))
                window[s[r]]++;

            while (covers(window, mp)) {
                int len = r - left + 1;
                if (len < bestLen) {
                    bestLen = len;
                    bestLeft = left;
                }
                if (mp.contains(s[left]))
                    window[s[left]]--;
                left++;
            }
        }

        return bestLeft == -1 ? "" : s.substr(bestLeft, bestLen);
    }
};
