/*
 * Problem #1871: Jump Game VII (Medium)
 * https://leetcode.com/problems/jump-game-vii/
 *
 * Approach: Prefix Sum on Reachability
 * We maintain a prefix sum array where prefix[i] counts the number of reachable
 * '0' positions among the first i indices. For each '0' position j, we check if
 * any position in the valid jump range [j-maxJump, j-minJump] was reachable by
 * querying the prefix sum in O(1), avoiding redundant iteration over the range.
 *
 * Time Complexity: O(n) - single pass over the string with O(1) range queries
 * using the prefix sum array, where n is the length of string s.
 *
 * Space Complexity: O(n) - for the prefix sum array of size n+1.
 *
 * Runtime: 4 ms
 * Memory: 29.1 MB
 */

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        prefix[1] = 1; 

        for (int j = 1; j < n; j++) {
            if (s[j] == '1') {
                prefix[j + 1] = prefix[j];
                continue;
            }
            int lo = max(0, j - maxJump);
            int hi = j - minJump;

            if (hi < 0) {
                prefix[j + 1] = prefix[j];
                continue;
            }

            int reachable = prefix[hi + 1] - prefix[lo];
            if (reachable > 0) prefix[j + 1] = prefix[j] + 1;
            else               prefix[j + 1] = prefix[j];
        }

        return prefix[n] - prefix[n - 1] > 0;
    }
};
