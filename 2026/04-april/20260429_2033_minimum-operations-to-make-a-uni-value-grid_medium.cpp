/*
 * Problem #2033 - Minimum Operations to Make a Uni-Value Grid (Medium)
 * URL: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
 *
 * Approach: Median Minimization
 * First, verify all elements share the same remainder when divided by x; if not, return -1.
 * Flatten the grid into a 1D array, sort it, and use the median as the target value.
 * The median minimizes the total absolute deviation, so sum up abs(v - median) / x for all elements.
 *
 * Time Complexity: O(m * n * log(m * n))
 *   - Flattening is O(m * n), sorting is O(m * n * log(m * n)), final summation is O(m * n).
 *
 * Space Complexity: O(m * n)
 *   - A flat array of all grid elements is stored for sorting.
 *
 * Runtime: 31 ms
 * Memory: 87.2 MB
 */

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int prec = grid[0][0] % x;
        
        vector<int> nums;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != prec) return -1;
                nums.push_back(grid[i][j]);
            }
        
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        
        int ops = 0;
        for (int v : nums)
            ops += abs(v - median) / x;
        
        return ops;
    }
};
