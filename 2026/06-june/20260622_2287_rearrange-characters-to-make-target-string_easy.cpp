/*
 * 2287. Rearrange Characters to Make Target String (Easy)
 * https://leetcode.com/problems/rearrange-characters-to-make-target-string/
 *
 * Approach: Frequency Count
 * Count the frequency of each character in both s and target using hash maps.
 * For each character required by target, compute how many complete copies can be
 * formed by dividing its count in s by its required count in target. The answer
 * is the minimum across all such characters.
 *
 * Time Complexity : O(n + m) where n = len(s) and m = len(target),
 *                   for building the two frequency maps and iterating over target chars.
 * Space Complexity: O(1) since the maps hold at most 26 distinct lowercase letters,
 *                   which is a constant bound regardless of input size.
 *
 * Runtime : 3 ms
 * Memory  : 8.7 MB
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
