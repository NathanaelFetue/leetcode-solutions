/*
 * Problem 3720: Lexicographically Smallest Permutation Greater Than Target
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
 *
 * Approach:
 * The key insight is that any permutation of the string strictly greater than the target must share a common prefix with the target of some length, diverge at the next index with a strictly larger character, and minimize the remaining suffix. By iterating over all possible divergence points, we verify if the prefix can be formed from the available character multiset, greedily select the smallest possible larger character for the split, and sort the remaining characters in ascending order to construct the smallest possible suffix. This greedy prefix exploration with suffix sorting guarantees that the lexicographically smallest of all valid candidates generated is the absolute minimum greater permutation.
 *
 * Time Complexity: O(N^2) — For each of the N possible split indices, we validate the prefix in O(N) time and build the candidate by filling the suffix in O(N) time using a fixed-size character frequency map.
 * Space Complexity: O(N) — Auxiliary space is required to store the candidate and result strings of length N, while the character frequency arrays use a constant O(1) space.
 *
 * Runtime: 23 ms | Memory: 18.2 MB
 */

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;

        string result = "";

        for (int i = 0; i < n; i++) {
            int cur[26];
            memcpy(cur, freq, sizeof(freq));

            bool ok = true;
            for (int j = 0; j < i; j++) {
                if (cur[target[j] - 'a'] > 0) cur[target[j] - 'a']--;
                else { ok = false; break; }
            }
            if (!ok) continue;

            char chosen = 0;
            for (char c = target[i] + 1; c <= 'z'; c++) {
                if (cur[c - 'a'] > 0) { chosen = c; cur[c - 'a']--; break; }
            }
            if (!chosen) continue;

            string candidate = target.substr(0, i) + chosen;
            for (char c = 'a'; c <= 'z'; c++)
                for (int k = 0; k < cur[c - 'a']; k++)
                    candidate += c;

            if (result.empty() || candidate < result)
                result = candidate;
        }
        return result;
    }
};
