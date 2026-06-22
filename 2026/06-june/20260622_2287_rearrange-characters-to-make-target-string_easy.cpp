/*
 * 2287. Rearrange Characters to Make Target String - Easy
 * https://leetcode.com/problems/rearrange-characters-to-make-target-string/
 *
 * Approach: Frequency Count with Division
 * Count the frequency of each character in both s and target using hash maps.
 * For each character required by target, compute how many times it can be
 * supplied from s by integer division (mp1[c] / freq), then take the minimum
 * across all target characters to determine the maximum number of copies.
 *
 * Time Complexity : O(n + m) where n = len(s) and m = len(target)
 *   - Single pass over each string to build frequency maps, then one pass
 *     over the unique characters in target.
 * Space Complexity: O(1) - at most 26 distinct lowercase letters stored in maps,
 *   so space is bounded by the alphabet size, not input length.
 *
 * Runtime : 1 ms
 * Memory  : 8.9 MB
 */

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> mp1, mp2;
        for (char c : s)      mp1[c]++;
        for (char c : target) mp2[c]++;

        int res = INT_MAX;
        for (auto& [c, freq] : mp2)
            res = min(res, mp1[c] / freq);

        return res;
    }
};
