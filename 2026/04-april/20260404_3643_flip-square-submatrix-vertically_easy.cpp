/*
 * Problem #3643 - Flip Square Submatrix Vertically
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/flip-square-submatrix-vertically/
 *
 * Approach: In-place vertical flip of a k×k submatrix starting at (x, y).
 * Iterate over the top half of the submatrix rows (k/2 iterations) and for each row,
 * swap all elements in that row with the corresponding mirrored row from the bottom.
 *
 * Time Complexity: O(k^2) - we process k/2 row pairs, each spanning k columns,
 * resulting in (k/2)*k total swap operations within the submatrix.
 *
 * Space Complexity: O(1) extra space - the flip is performed in-place on the grid;
 * no additional data structures are used beyond loop variables.
 *
 * Runtime: 4 ms | Memory: 33.8 MB
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
