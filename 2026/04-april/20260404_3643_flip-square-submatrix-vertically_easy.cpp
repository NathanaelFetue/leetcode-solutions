/*
 * Problem #3643 - Flip Square Submatrix Vertically
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/flip-square-submatrix-vertically/
 *
 * Approach: In-place vertical flip of a k×k submatrix starting at (x, y).
 * Iterate over the top half of the submatrix rows (i from 0 to k/2 - 1) and
 * swap each element in row (x+i) with its mirror in row (x+k-1-i) across all k columns.
 *
 * Time Complexity: O(k^2) - we process approximately k/2 * k element swaps
 * within the submatrix bounds.
 * Space Complexity: O(1) - the flip is performed in-place with no extra storage
 * beyond the swap temporary variable.
 *
 * Runtime: 0 ms
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
