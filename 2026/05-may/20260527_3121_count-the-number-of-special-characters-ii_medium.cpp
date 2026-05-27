/*
 * Problem #3121 - Count the Number of Special Characters II (Medium)
 * https://leetcode.com/problems/count-the-number-of-special-characters-ii/
 *
 * Approach: Track the last occurrence of each lowercase letter and the first
 * occurrence of each uppercase letter across the word. A character qualifies
 * as special if its last lowercase occurrence strictly precedes its first
 * uppercase occurrence, ensuring no uppercase appears before all its lowercases.
 *
 * Time Complexity: O(n) - single pass over the word to fill position arrays,
 * followed by O(26) = O(1) pass to count valid special characters.
 *
 * Space Complexity: O(1) - two fixed-size arrays of length 26 for tracking
 * last lowercase and first uppercase positions, independent of input size.
 *
 * Runtime: 76 ms | Memory: 24.4 MB
 */

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);  // dernière pos lowercase
        vector<int> firstUpper(26, INT_MAX); // première pos uppercase

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c))
                lastLower[c - 'a'] = i;
            else
                firstUpper[c - 'A'] = min(firstUpper[c - 'A'], i);
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 && firstUpper[i] != INT_MAX)
                if (lastLower[i] < firstUpper[i])
                    count++;
        }
        return count;
    }
};
