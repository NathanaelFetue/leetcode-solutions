/*
 * Problem #3016: Minimum Number of Pushes to Type Word II (Medium)
 * https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
 *
 * Approach: Greedy with frequency sorting.
 * Count the frequency of each character, then sort frequencies in descending order.
 * Assign the most frequent characters to the first 8 slots (1 push each), next 8 to 2 pushes, and so on, mimicking optimal phone keypad assignment.
 *
 * Key Insight: A phone keypad has 8 usable keys (2-9). Characters assigned to position i (0-indexed)
 * require (i / 8) + 1 pushes. Greedily assigning high-frequency characters to low-push slots minimizes total pushes.
 *
 * Time Complexity : O(n + 26 log 26) = O(n), where n is the length of the word.
 *   - O(n) to build frequency array, O(26 log 26) constant sort over fixed-size array.
 * Space Complexity : O(1) - only a fixed-size frequency array of 26 integers is used.
 *
 * Runtime : 9 ms
 * Memory  : 25.5 MB
 */

class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};
        for (char c : word) freq[c - 'a']++;
        sort(freq, freq + 26, greater<int>());

        int res = 0;
        for (int i = 0; i <= 25; i++) res += freq[i] * ((i / 8) + 1);
        return res;
    }
};
