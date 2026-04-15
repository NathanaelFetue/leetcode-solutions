/*
 * Problem #14 - Longest Common Prefix (Easy)
 * https://leetcode.com/problems/longest-common-prefix/
 *
 * Approach: Iterative Prefix Reduction
 * Start with the first string as the candidate longest common prefix.
 * For each subsequent string, repeatedly trim the last character of the prefix
 * until it matches the start (index 0) of the current string, or until the prefix becomes empty.
 *
 * Time Complexity: O(S) where S is the total number of characters across all strings,
 * in the worst case every character is compared during prefix reduction.
 *
 * Space Complexity: O(1) extra space beyond the output; the prefix is modified in-place
 * and no additional data structures are used.
 *
 * Runtime: 0 ms
 * Memory: 11.8 MB
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(lcp) != 0) {
                lcp = lcp.substr(0, lcp.size() - 1);
                if (lcp.empty()) return "";
            }
        }
        return lcp;
    }
};
