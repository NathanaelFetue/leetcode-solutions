/*
 * Problem 3499: Maximize Active Section with Trade I (Medium)
 * https://leetcode.com/problems/maximize-active-section-with-trade-i/
 *
 * Approach: Run-length encode the string (padded with sentinel '1's on both ends)
 * to form blocks of consecutive characters. For each block of '1's that is flanked
 * on both sides by blocks of '0's, compute the gain from merging those two '0' blocks
 * into the '1' block via a trade. Track the maximum such gain and add it to the
 * baseline count of '1's in the original string.
 *
 * Time Complexity: O(n) - single pass to build blocks, single pass over blocks to
 * find maximum gain, plus O(n) to count original '1's.
 *
 * Space Complexity: O(n) - storage for the padded string and the run-length encoded
 * blocks vector.
 *
 * Runtime: 139 ms | Memory: 175.9 MB
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
