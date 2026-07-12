/*
 * Problem #76 - Minimum Window Substring (Hard)
 * https://leetcode.com/problems/minimum-window-substring/
 *
 * Approach: Sliding Window with Two Hash Maps
 * Maintain a sliding window [left, r] over string s, expanding right to include characters
 * from t and shrinking left whenever the window fully covers all required characters.
 * The covers() helper checks if the current window satisfies all character frequency
 * requirements from t. Track the smallest valid window found throughout.
 *
 * Time Complexity: O(n * m) where n = len(s) and m = len(t) due to covers() being
 * called O(n) times with O(m) work each call. Can be optimized to O(n + m) with a counter.
 *
 * Space Complexity: O(m) for the two hash maps storing at most |t| unique characters.
 *
 * Runtime: 90 ms | Memory: 11.6 MB
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
