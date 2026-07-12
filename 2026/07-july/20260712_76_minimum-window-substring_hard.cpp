/*
 * Problem #76 - Minimum Window Substring (Hard)
 * URL: https://leetcode.com/problems/minimum-window-substring/
 *
 * Approach: Sliding Window with Two Hash Maps
 * Maintain a sliding window [left, right] over string s, expanding right to include characters
 * and shrinking left whenever the window fully covers all characters in t. A helper function
 * checks coverage by comparing character frequencies in the window against those required by t.
 * The smallest valid window encountered is recorded and returned.
 *
 * Time Complexity: O(|s| * |t|) in the worst case — the covers() check iterates over all
 * unique characters in t for each window shrink step. With a fixed alphabet this is O(|s|).
 *
 * Space Complexity: O(|s| + |t|) for the two frequency hash maps storing character counts.
 *
 * Runtime: 87 ms | Memory: 11.4 MB
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
