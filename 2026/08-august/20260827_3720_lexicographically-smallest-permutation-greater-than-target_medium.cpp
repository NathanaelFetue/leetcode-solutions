/*
 * Problem 3720: Lexicographically Smallest Permutation Greater Than Target
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
 *
 * Approach:
 * The key insight is that any permutation of `s` strictly greater than `target` must share a common prefix with `target` up to some index `i - 1`, have a strictly larger character at index `i`, and have the remaining characters sorted in ascending order to minimize the suffix. We iterate over all possible branch-off indices `i` from `0` to `n - 1`. For each index, we verify if `s` contains the required prefix `target[0...i-1]`, find the smallest available character greater than `target[i]` to place at index `i`, and greedily append the rest of the characters in sorted order. By comparing the resulting candidates for all valid branch-off points, we find the globally lexicographically smallest permutation.
 *
 * Time Complexity: O(N^2) — the outer loop runs N times for each possible branch-off index, and inside the loop, verifying the prefix and constructing the candidate string takes O(N) time.
 * Space Complexity: O(N) — to store the candidate and result strings of length N, with O(1) auxiliary space for the fixed-size character frequency arrays.
 *
 * Runtime: 17 ms | Memory: 18.1 MB
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
