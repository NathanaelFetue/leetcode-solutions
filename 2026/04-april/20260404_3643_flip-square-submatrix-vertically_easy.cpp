/*
 * Problem #3643 - Flip Square Submatrix Vertically
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/flip-square-submatrix-vertically/
 *
 * Approach/Algorithm:
 * The solution performs an in-place vertical flip of a k×k submatrix starting at position (x, y).
 * It iterates over the top half of the submatrix rows and swaps each element with its corresponding
 * element in the mirrored row from the bottom, effectively reversing the submatrix vertically.
 *
 * Time Complexity: O(k²) — We iterate over k/2 rows and k columns, performing a constant-time swap
 * for each element, resulting in approximately k²/2 total swaps.
 *
 * Space Complexity: O(1) — The flip is performed in-place with no additional data structures;
 * the returned grid is the same modified input grid.
 *
 * Runtime: 0 ms
 * Memory: 33.8 MB
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
