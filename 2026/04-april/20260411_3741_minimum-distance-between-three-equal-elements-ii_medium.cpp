/*
 * Problem #3741 - Minimum Distance Between Three Equal Elements II
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
 *
 * Approach: Next-Occurrence Precomputation
 * First, build a 'next' array where next[i] stores the index of the next occurrence
 * of nums[i] in the array, computed via a reverse pass with a hash map. Then iterate
 * through all valid triples (i, next[i], next[next[i]]) to find the minimum span,
 * returning twice that span as the answer (or -1 if no valid triple exists).
 *
 * Time Complexity: O(n) - two linear passes over the array plus O(1) hash map ops.
 * Space Complexity: O(n) - for the 'next' array and the occurrence hash map.
 *
 * Runtime: 189 ms
 * Memory: 272.7 MB
 */

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> next(n, -1);
        std::unordered_map<int, int> occur;
        int ans = n + 1;

        for (int i = n - 1; i >= 0; i--) {
            if (occur.count(nums[i])) {
                next[i] = occur[nums[i]];
            }
            occur[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int secondPos = next[i];
            if (secondPos != -1) {
                int thirdPos = next[secondPos];
                if (thirdPos != -1) {
                    ans = std::min(ans, thirdPos - i);
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
};
