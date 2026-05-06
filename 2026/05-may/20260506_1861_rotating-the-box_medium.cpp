/*
 * Problem #1861 - Rotating the Box
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/rotating-the-box/
 *
 * Approach: Two-phase simulation.
 * Phase 1 applies gravity rightward: for each row, track the next available empty slot
 * and slide each stone '#' to the rightmost possible position, resetting on obstacles '*'.
 * Phase 2 performs a 90-degree clockwise rotation by remapping each cell (i, j)
 * to position (j, m-1-i) in the result matrix.
 *
 * Time Complexity: O(m * n) — each cell is visited a constant number of times
 * across both the gravity pass and the rotation step.
 * Space Complexity: O(m * n) — the result matrix of size n x m is the only
 * extra allocation; gravity is applied in-place.
 *
 * Runtime: 9 ms | Memory: 56.6 MB
 */

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();

        // Étape 1 — gravité : les pierres tombent vers la droite
        for (int i = 0; i < m; i++) {
            int empty = n - 1; // prochaine case vide
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    empty = j - 1; // obstacle > reset
                } else if (boxGrid[i][j] == '#') {
                    boxGrid[i][j] = '.';
                    boxGrid[i][empty] = '#';
                    empty--;
                }
            }
        }

        // Étape 2 — rotation 90° horaire
        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res[j][m - 1 - i] = boxGrid[i][j];

        return res;
    }
};
