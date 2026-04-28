/*
 * Problem 2033: Minimum Operations to Make a Uni-Value Grid (Medium)
 * https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
 *
 * Approach: Flatten the 2D grid into a 1D array and verify all elements share the same
 * remainder when divided by x (otherwise return -1). Sort the array and use the median
 * as the optimal target value, since the median minimizes the sum of absolute deviations.
 * Sum up the number of x-steps each element needs to reach the median.
 *
 * Time Complexity: O(m*n log(m*n)) — dominated by sorting all m*n grid elements.
 * Space Complexity: O(m*n) — for the flattened nums array storing all grid values.
 *
 * Runtime: 35 ms
 * Memory: 90.2 MB
 */

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (auto& row : grid)
            for (int v : row) nums.push_back(v);
        
        int rem = nums[0] % x;
        for (int v : nums)
            if (v % x != rem) return -1;
        
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        
        int ops = 0;
        for (int v : nums)
            ops += abs(v - median) / x;
        
        return ops;
    }
};
