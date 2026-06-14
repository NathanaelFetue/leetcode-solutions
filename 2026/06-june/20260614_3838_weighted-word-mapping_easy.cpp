/*
 * Problem #3838 - Weighted Word Mapping
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/weighted-word-mapping/
 *
 * Approach/Algorithm:
 * For each word, compute a weighted sum by accumulating the weight of each character
 * (indexed by its offset from 'a'). The sum is then taken modulo 26 and subtracted
 * from 'z' to map it to a single output character, which is appended to the result string.
 *
 * Time Complexity: O(N * L) where N is the number of words and L is the average word
 * length, as every character in every word is visited exactly once.
 *
 * Space Complexity: O(N) for the output string, which stores one character per word.
 * No additional data structures are used beyond the result buffer.
 *
 * Runtime: 0 ms | Memory: 43.7 MB
 */

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        ans.reserve(words.size());
        for (string word : words) {
            int s = 0;
            for (char c : word) {
                s += weights[c - 'a'];
            }
            ans += 'z' - s % 26;
        }
        return ans;
    }
};
