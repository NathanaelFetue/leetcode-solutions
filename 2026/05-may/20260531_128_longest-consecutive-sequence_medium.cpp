/*
 * Problem #128 - Longest Consecutive Sequence (Medium)
 * https://leetcode.com/problems/longest-consecutive-sequence/
 *
 * Approach: Hash Set with Sequence Start Detection
 * All numbers are inserted into an unordered_set for O(1) lookups.
 * For each number, we only begin counting if it is the start of a sequence
 * (i.e., x-1 does not exist in the set), then extend the sequence forward
 * using a while loop, tracking the maximum length found.
 *
 * Time Complexity: O(n) - each number is visited at most twice across all
 * sequence expansions (once as a potential start, once during extension).
 * Space Complexity: O(n) - unordered_set stores all n unique elements.
 *
 * Runtime: 83 ms
 * Memory: 88.9 MB
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;

        for (int x : s) {
            if (s.count(x - 1)) continue;

            int len = 1;
            while (s.count(x + len)) len++;

            best = max(best, len);
        }
        return best;
    }
};
