/*
 * Problem #36 - Valid Sudoku (Medium)
 * LeetCode URL: https://leetcode.com/problems/valid-sudoku/
 *
 * Approach: Hash Set Tracking
 * Iterate through every cell once, using three arrays of hash sets (one per row, column,
 * and 3x3 box) to track seen digits. For each non-empty cell, check if the digit already
 * exists in its corresponding row, column, or box set; if so, return false immediately.
 * The 3x3 box index is computed as (i/3)*3 + (j/3), mapping each cell to one of 9 boxes.
 *
 * Time Complexity: O(1) - The board is always 9x9 (81 cells), so iteration is constant.
 * Space Complexity: O(1) - At most 9 digits stored across 27 fixed-size hash sets (bounded).
 *
 * Runtime: 1 ms
 * Memory: 25.7 MB
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9], boxes[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;

                int box = (i/3)*3 + (j/3); // index de la box 0-8

                if (rows[i].count(c) || cols[j].count(c) || boxes[box].count(c))
                    return false;

                rows[i].insert(c);
                cols[j].insert(c);
                boxes[box].insert(c);
            }
        }
        return true;
    }
};
