/*
 * Problem #3110 - Score of a String
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/score-of-a-string/
 *
 * Approach/Algorithm:
 * Iterate through the string once, computing the absolute difference between
 * each pair of adjacent characters and accumulating the total sum. This is a
 * straightforward single-pass linear scan requiring no extra data structures.
 *
 * Time Complexity: O(n) - where n is the length of the string, as we visit
 * each adjacent pair exactly once in a single loop.
 *
 * Space Complexity: O(1) - only a single integer accumulator is used,
 * regardless of input size.
 *
 * Runtime: 0 ms | Memory: 8.8 MB
 */

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for (int i = 0; i < s.size() - 1; i++)
            score += abs(s[i] - s[i+1]);
        return score;
    }
};
