/*
 * 944. Delete Columns to Make Sorted
 * Difficulty: Easy
 * https://leetcode.com/problems/delete-columns-to-make-sorted/
 *
 * Approach: Column-by-column vertical scan.
 * For each column index, iterate through consecutive row pairs to check if the column
 * is sorted in non-decreasing order. If any adjacent pair violates this, increment the
 * deletion count and move to the next column immediately via a break.
 *
 * Time Complexity: O(m * n) where m is the number of rows and n is the number of columns.
 * Each cell is visited at most once per column check.
 *
 * Space Complexity: O(1) — only a constant number of integer variables are used,
 * no additional data structures are allocated.
 *
 * Runtime: 0 ms
 * Memory: 15.4 MB
 */

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int rows = strs.size();
        int cols = strs[0].size();

        for (int j = 0; j < cols; j++) {       
            for (int i = 0; i < rows - 1; i++) {
                if (strs[i][j] > strs[i+1][j]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
