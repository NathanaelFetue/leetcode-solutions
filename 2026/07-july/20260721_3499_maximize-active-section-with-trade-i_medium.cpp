/*
 * Problem 3499: Maximize Active Section with Trade I (Medium)
 * https://leetcode.com/problems/maximize-active-section-with-trade-i/
 *
 * Approach: Run-length encode the string (padded with sentinel '1's on both ends)
 * to form a list of character-count blocks. Then scan for any block of '1's flanked
 * on both sides by blocks of '0's; the best trade merges those two '0' blocks into
 * active '1's, so we track the maximum combined length of such neighboring '0' pairs.
 * The answer is the original count of '1's plus this maximum gain.
 *
 * Time Complexity: O(n) - single pass for run-length encoding, one pass over blocks,
 * and one pass to count ones, all linear in the length of the input string.
 *
 * Space Complexity: O(n) - the blocks vector and padded string each take O(n) space
 * in the worst case (alternating characters produce O(n) blocks).
 *
 * Runtime: 175 ms | Memory: 175.9 MB
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
