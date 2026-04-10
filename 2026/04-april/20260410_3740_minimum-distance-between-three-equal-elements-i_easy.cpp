/*
 * Problem #3740 - Minimum Distance Between Three Equal Elements I
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/
 *
 * Approach: Brute-force triple nested loop over all index triplets (i, j, k).
 * For each triplet where all three values are equal, compute the total pairwise
 * distance as |i-j| + |j-k| + |k-i| and track the minimum across all valid triplets.
 * Return -1 if no such triplet exists.
 *
 * Time Complexity: O(n^3) - three nested loops iterating over all index combinations.
 * Space Complexity: O(1) - only a constant number of variables used regardless of input size.
 *
 * Runtime: 7 ms
 * Memory: 28.8 MB
 */

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(), res = INT_MAX;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                for (int k = j+1; k < n; k++)
                    if (nums[i] == nums[j] && nums[j] == nums[k])
                        res = min(res, abs(i-j) + abs(j-k) + abs(k-i));
        return res == INT_MAX ? -1 : res;
    }
};
