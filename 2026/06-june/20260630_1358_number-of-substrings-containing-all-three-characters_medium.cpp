/*
 * Problem #1358: Number of Substrings Containing All Three Characters (Medium)
 * https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 *
 * Approach: Sliding Window
 * Use a two-pointer sliding window to find the smallest window containing all three characters (a, b, c).
 * When a valid window [left, right] is found, all substrings starting from left to right and extending
 * to the end of the string are valid, so we add (len - right) to the total count, then shrink from the left.
 *
 * Time Complexity: O(n) - each character is added and removed from the window at most once,
 * where n is the length of the input string.
 *
 * Space Complexity: O(1) - only a fixed-size frequency array of length 3 is used,
 * regardless of input size.
 *
 * Runtime: 8 ms | Memory: 11.1 MB
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        int left = 0, right = 0;
        // Track frequency of a, b, c
        vector<int> freq(3, 0);
        int total = 0;

        while (right < len) {
            // Add character at right pointer to frequency array
            char curr = s[right];
            freq[curr - 'a']++;

            // While we have all required characters
            while (hasAllChars(freq)) {
                // All substrings from current window to end are valid
                // Add count of these substrings to result
                total += len - right;

                // Remove leftmost character and move left pointer
                char leftChar = s[left];
                freq[leftChar - 'a']--;
                left++;
            }

            right++;
        }

        return total;
    }

private:
    bool hasAllChars(vector<int>& freq) {
        // Check if we have at least one of each character
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
};
