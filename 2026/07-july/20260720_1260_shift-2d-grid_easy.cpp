/*
 * Problem #1260 - Shift 2D Grid (Easy)
 * https://leetcode.com/problems/shift-2d-grid/
 *
 * Approach: Three-Rotation Reversal (In-Place)
 * The grid is treated as a flattened 1D array of size n = r*c, and k is reduced modulo n.
 * Using the classic array rotation trick, the entire array is reversed, then the first k elements
 * are reversed, and finally the remaining elements are reversed, producing a right-shift by k.
 * Cell (i, j) in the 2D grid is accessed via index i*c + j, mapped back using row = idx/c, col = idx%c.
 *
 * Time Complexity: O(n) where n = r * c (each element is swapped at most once across all three reversals)
 * Space Complexity: O(1) extra space — rotation is done in-place on the original grid
 *
 * Runtime: 0 ms
 * Memory: 18.2 MB
 */

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (!k) return grid;
        int r = grid.size(), c = grid[0].size();
        int n = r * c;

        k = k % n;
        if (!k) return grid;

        auto shift = [&](int i, int j) {
            while (i < j) {
                swap(grid[i / c][i % c], grid[j / c][j % c]);
                i++;
                j--;
            }
        };

        shift(0, n - 1);
        shift(0, k - 1);
        shift(k, n - 1);

        return grid;
    }
};
