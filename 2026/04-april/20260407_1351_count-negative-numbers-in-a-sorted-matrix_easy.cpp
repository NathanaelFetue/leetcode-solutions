/*
 * Problem #1351 - Count Negative Numbers in a Sorted Matrix
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
 *
 * Approach: Two-pointer staircase traversal starting from the top-right corner of the matrix.
 * Since rows are sorted in descending order and columns are sorted in descending order,
 * if grid[row][col] is negative, all elements below it in the same column are also negative.
 *
 * Algorithm:
 * - Start at top-right corner (row=0, col=n-1).
 * - If current element is negative, add (m - row) to count and move left (col--).
 * - If current element is non-negative, move down (row++) to find negatives.
 *
 * Time Complexity: O(m + n) - at most m + n steps since row and col each move in one direction.
 * Space Complexity: O(1) - only constant extra variables used.
 *
 * Runtime: 0 ms | Memory: 14.2 MB
 */

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        int row = 0, col = n - 1;

        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                count += m - row; 
                col--;       
            } else {
                row++;          
            }
        }
        return count;
    }
};
