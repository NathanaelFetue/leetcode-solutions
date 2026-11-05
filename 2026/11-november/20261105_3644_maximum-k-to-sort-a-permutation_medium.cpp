/*
 * Problem 3644: Maximum K to Sort a Permutation
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/
 *
 * Approach:
 * To determine the maximum valid $k$ for sorting the permutation, we only need to constrain operations based on elements that are out of place. The key insight is that any element requiring relocation must be able to participate in bitwise operations under $k$, meaning $k$ can only contain bits that are set in every misplaced element. Using Bitwise AND Reduction, we iterate through the array and accumulate the bitwise AND of all elements where `nums[i] != i`. This bitwise intersection yields the largest integer $k$ containing only the set bits common to all elements that must be moved. If all elements are already at their target indices, no swaps are needed, so we return 0.
 *
 * Time Complexity: O(N) - a single pass through the array to check indices and perform bitwise AND operations.
 * Space Complexity: O(1) - operates in-place using a constant number of auxiliary variables.
 *
 * Runtime: 4 ms | Memory: 152.6 MB
 */

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] == i) {
                continue;
            }
            res &= nums[i];
        }
        return res == INT_MAX ? 0 : res;
    }
};
