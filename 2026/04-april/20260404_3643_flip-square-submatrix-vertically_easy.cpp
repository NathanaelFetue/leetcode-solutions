/*
 * Problem #3643: Flip Square Submatrix Vertically
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/flip-square-submatrix-vertically/
 *
 * Approach/Algorithm:
 * The solution performs an in-place vertical flip of a k×k submatrix starting at position (x, y).
 * It iterates over the top half of the submatrix rows and swaps each element with its mirror
 * row from the bottom, column by column, effectively reversing the submatrix vertically.
 *
 * Time Complexity: O(k^2) — we process k/2 rows, each with k column swaps, totaling ~k²/2 operations.
 * Space Complexity: O(1) — the flip is done in-place with no additional data structures used.
 *
 * Runtime: 3 ms
 * Memory: 33.9 MB
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
