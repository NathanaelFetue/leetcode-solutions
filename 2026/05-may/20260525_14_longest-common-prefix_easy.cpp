/*
 * Problem 14: Longest Common Prefix
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/longest-common-prefix/
 *
 * Approach: Character-by-character vertical scanning using the first string as reference.
 * Iterate over each character of the first string, then check if every other string
 * has the same character at the same position. Return the result as soon as a mismatch is found.
 *
 * Time Complexity: O(S) where S is the total number of characters across all strings in the
 * worst case (all strings share a full common prefix). In practice, O(n * m) where n is the
 * number of strings and m is the length of the shortest/common prefix.
 *
 * Space Complexity: O(1) extra space beyond the output string, as no auxiliary data structures are used.
 *
 * Runtime: 0 ms
 * Memory: 11.8 MB
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        string deb = strs[0];
        int j = 0;
        for(auto c: deb) {
            for(int  i = 1; i<strs.size(); i++) {
                if ( strs[i][j] == c) continue;
                else return res;
            }
            res += c;
            j++;
        }
        return res;
    }
};
