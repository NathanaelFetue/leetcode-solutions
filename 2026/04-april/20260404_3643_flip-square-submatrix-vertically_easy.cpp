/*
 * Problem #3643 - Flip Square Submatrix Vertically
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/flip-square-submatrix-vertically/
 *
 * Approach/Algorithm:
 * To flip a k×k submatrix vertically (top-to-bottom), we swap rows symmetrically
 * around the horizontal center of the submatrix. For each pair of rows (i from top,
 * corresponding row from bottom), we swap all k elements within the column range [y, y+k).
 *
 * Time Complexity: O(k^2) - We iterate over k/2 row pairs and k columns per pair,
 * resulting in roughly k^2/2 swap operations within the submatrix.
 *
 * Space Complexity: O(1) - The flip is done in-place with no additional data structures;
 * we return the modified grid reference.
 *
 * Runtime: 2 ms
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
