/*
 * Problem #3499: Maximize Active Section with Trade I (Medium)
 * https://leetcode.com/problems/maximize-active-section-with-trade-i/
 *
 * Approach: Run-length encode the string (padded with sentinel '1's on both ends)
 * to form blocks of consecutive characters. For each block of '1's flanked by
 * two blocks of '0's, compute the total zeros gained by merging those zero blocks
 * around the ones block, tracking the maximum such gain.
 *
 * The answer is the count of existing '1's in the original string plus the best
 * gain achievable from a single trade (converting a '1'-block to '0's and merging
 * adjacent zero blocks).
 *
 * Time Complexity: O(n) - single pass to build blocks, single pass over blocks.
 * Space Complexity: O(n) - for the block list and padded string.
 *
 * Runtime: 167 ms | Memory: 176 MB
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
