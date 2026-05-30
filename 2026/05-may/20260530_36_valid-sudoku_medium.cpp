/*
 * Problem #36 - Valid Sudoku (Medium)
 * https://leetcode.com/problems/valid-sudoku/
 *
 * Approach: Hash Set Tracking
 * Use three arrays of unordered sets (one per row, column, and 3x3 box) to track
 * seen digits. For each non-empty cell, compute its box index as (i/3)*3 + (j/3),
 * then check and insert into the corresponding row, column, and box sets.
 *
 * Time Complexity: O(1) — The board is always 9x9 (81 cells), so iteration is constant.
 * Space Complexity: O(1) — At most 9 sets of 9 elements each for rows, cols, and boxes;
 *                          all bounded by the fixed 9x9 board size.
 *
 * Runtime : 6 ms
 * Memory  : 25.8 MB
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
