/*
 * Problem #3643 - Flip Square Submatrix Vertically
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/flip-square-submatrix-vertically/
 *
 * Approach: In-place vertical flip of a k×k submatrix starting at (x, y).
 * Iterate through the top half of the submatrix rows (k/2 iterations) and for each
 * row pair (i and k-1-i), swap all elements column by column across the full width k.
 *
 * Time Complexity: O(k^2) — iterates over k/2 rows and k columns per row pair,
 * covering all k^2 cells in the submatrix.
 *
 * Space Complexity: O(1) extra space — the flip is done in-place using only a
 * temporary swap variable; the output is the modified input grid itself.
 *
 * Runtime: 4 ms | Memory: 34 MB
 */

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; i++) {
            for (int j = y; j < y + k; j++) {
                swap(grid[x + i][j], grid[x + k - 1 - i][j]);
            }
        }
        return grid;
    }
};
