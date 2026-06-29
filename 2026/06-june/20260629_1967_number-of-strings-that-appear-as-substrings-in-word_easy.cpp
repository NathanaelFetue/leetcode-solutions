/*
 * Problem 1967: Number of Strings That Appear as Substrings in Word
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
 *
 * Approach: Sliding Window Substring Matching
 * For each pattern, a sliding window of the pattern's length is slid across the word.
 * At each position, a character-by-character comparison checks if the pattern matches the current window, returning true on the first match found.
 * The count of patterns that match at least one window position is accumulated and returned.
 *
 * Time Complexity: O(P * M * N) where P is the number of patterns, M is the average
 * pattern length, and N is the length of word. Each pattern requires O(M * N) matching.
 *
 * Space Complexity: O(1) extra space, only a few integer variables are used per check.
 *
 * Runtime: 2 ms
 * Memory: 11.6 MB
 */

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        auto check = [](const string& pattern, const string& word) -> bool {
            int m = pattern.size();
            int n = word.size();
            for (int i = 0; i + m <= n; ++i) {
                bool flag = true;
                for (int j = 0; j < m; ++j) {
                    if (word[i + j] != pattern[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;
                }
            }
            return false;
        };

        int res = 0;
        for (const string& pattern : patterns) {
            res += check(pattern, word);
        }
        return res;
    }
};
