/*
 * Problem 3499: Maximize Active Section with Trade I (Medium)
 * https://leetcode.com/problems/maximize-active-section-with-trade-i/
 *
 * Approach: Run-length encode the string (padded with sentinel '1's on both ends)
 * to form blocks of consecutive characters. Then scan for any '1'-block flanked
 * by two '0'-blocks, tracking the maximum combined size of those two '0'-blocks
 * as the best possible gain from a single trade.
 *
 * The answer is the total count of '1's in the original string plus the maximum
 * gain found, since trading converts the flanking zeros into active sections.
 *
 * Time Complexity: O(n) — single pass for RLE encoding, one pass over blocks,
 * and one pass to count ones; all linear in string length n.
 *
 * Space Complexity: O(n) — storage for the padded string and the blocks vector,
 * both proportional to input size.
 *
 * Runtime: 195 ms | Memory: 176 MB
 */

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int n = t.size();

        vector<pair<char,int>> blocks;
        int i = 0;
        while (i < n) {
            char c = t[i];
            int j = i;
            while (j < n && t[j] == c) j++;
            blocks.push_back({c, j - i});
            i = j;
        }

        int ones = count(s.begin(), s.end(), '1');
        int maxGain = 0;

        for (int k = 1; k + 1 < (int)blocks.size(); k++) {
            if (blocks[k].first == '1' &&
                blocks[k-1].first == '0' &&
                blocks[k+1].first == '0') {
                maxGain = max(maxGain, blocks[k-1].second + blocks[k+1].second);
            }
        }

        return ones + maxGain;
    }
};
