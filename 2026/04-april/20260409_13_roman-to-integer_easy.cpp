/*
 * Problem #13: Roman to Integer
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/roman-to-integer/
 *
 * Approach: Greedy two-character lookahead with hash map lookup.
 * A map stores all valid single and two-character Roman numeral tokens (including subtractive pairs like IV, IX, XL, etc.).
 * The string is scanned left to right; at each position, we first attempt to match a two-character token, and if found, add its value and advance by 2; otherwise we match a single character and advance by 1.
 *
 * Time Complexity: O(n) - single linear pass through the string of length n.
 * Space Complexity: O(1) - the map has a fixed number of entries (13); the character vector scales with input but is bounded by Roman numeral practical limits.
 *
 * Runtime: 24 ms
 * Memory: 18.8 MB
 */

class Solution {
public:
    int romanToInt(string s) {
        map<string, int> mp = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
        if (s.size() ==1) return mp[s];
        vector<char> val;
        for (char c: s) val.push_back(c);

        int res =0;
        string tmp;
        int i = 0;
        while (i < val.size()) {
            if (i + 1 < val.size()) {
                tmp = string(1, val[i]) + string(1, val[i+1]);
                if (mp.contains(tmp)) {
                    res += mp[tmp];
                    i += 2;
                    continue;
                }
            }
            res += mp[string(1, val[i])];
            i++;
        }
        return res;

    }
};
