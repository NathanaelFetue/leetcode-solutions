/*
 * Problem #49 - Group Anagrams (Medium)
 * LeetCode: https://leetcode.com/problems/group-anagrams/
 *
 * Approach: Sorted-Key Hash Map
 * For each string, a sorted version is computed and used as a key in an unordered_map.
 * Strings that are anagrams of each other will produce the same sorted key, so they are
 * grouped together under that key. Finally, all map values are collected into the result.
 *
 * Time Complexity: O(n * k log k)
 *   - n = number of strings, k = maximum length of a string
 *   - Sorting each string takes O(k log k), done for all n strings
 *
 * Space Complexity: O(n * k)
 *   - The hash map stores all n strings, each of length up to k
 *
 * Runtime : 11 ms
 * Memory  : 25 MB
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& [key, group] : mp)
            res.push_back(group);

        return res;
    }
};
